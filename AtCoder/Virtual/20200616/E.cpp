#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, M;
ll A[100005];
ll S[100005];

bool check(ll x) {
    ll num = 0;
    REP(i, N) {
        ll ok = -1, ng = N;
        while (abs(ng - ok) > 1) {
            ll mid = (ng + ok) / 2;
            if (A[mid] + A[i] >= x)
                ok = mid;
            else
                ng = mid;
        }
        num += ok + 1;
    }
    return num <= M;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N, greater<ll>());

    ll mx = INF, ng = 0;
    while (abs(ng - mx) > 1) {
        ll mid = (ng + mx) / 2;
        if (check(mid))
            mx = mid;
        else
            ng = mid;
    }

    memset(S, 0, sizeof(S));
    REP(i, N) {
        S[i + 1] += S[i] + A[i];
    }
    ll ans = 0;
    ll num = 0;
    REP(i, N) {
        ll ok = -1, ng = N;
        while (abs(ng - ok) > 1) {
            ll mid = (ng + ok) / 2;
            if (A[mid] + A[i] >= mx)
                ok = mid;
            else
                ng = mid;
        }
        ll n = ok + 1;
        ans += n * A[i] + S[n];
        num += n;
    }

    ans += (M - num) * (mx - 1);
    cout << ans << endl;
    return 0;
}