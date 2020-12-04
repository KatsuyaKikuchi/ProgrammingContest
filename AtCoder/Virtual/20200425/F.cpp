#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
ll N, M;

ll count(ll m) {
    ll ret = 0;
    REP(i, N) {
        ll ok = -1, ng = N;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (A[i] + A[mid] >= m)
                ok = mid;
            else
                ng = mid;
        }
        ret += ok + 1;
    }
    return ret;
}

ll S[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N, greater<ll>());
    memset(S, 0, sizeof(S));
    REP(i, N) {
        S[i] += A[i];
        S[i + 1] += S[i];
    }

    ll border = 1e7, ng = 0;
    while (abs(ng - border) > 1) {
        ll mid = (ng + border) / 2;
        if (count(mid) <= M)
            border = mid;
        else
            ng = mid;
    }

    ll ans = (border - 1) * (M - count(border));
    REP(i, N) {
        ll ok = -1, ng = N;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (A[i] + A[mid] >= border)
                ok = mid;
            else
                ng = mid;
        }

        if (ok < 0)
            continue;
        ans += S[ok] + A[i] * (ok + 1);
    }

    cout << ans << endl;
    return 0;
}