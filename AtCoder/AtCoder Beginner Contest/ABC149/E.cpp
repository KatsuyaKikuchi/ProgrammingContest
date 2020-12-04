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

bool check(ll n) {
    ll m = 0;
    REP(i, N) {
        ll ok = i - 1, ng = N;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (A[i] + A[mid] > n)
                ok = mid;
            else
                ng = mid;
        }
        if (ok < i)
            continue;
        ll t = (ok - i) * 2 + 1;
        m += t;
    }
    return m <= M;
}

int main() {

    cin >> N >> M;
    memset(S, 0, sizeof(S));
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N, [](ll a, ll b) { return a > b; });
    REP(i, N) {
        S[i] += A[i];
        S[i + 1] += S[i];
    }

    ll lim = 0;
    {
        ll ok = INF, ng = 0;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (check(mid))
                ok = mid;
            else
                ng = mid;
        }
        lim = ok;
    }

    //! 和がok超であれば、含まれる。
    ll ans = 0;
    REP(i, N) {
        ll ok = i - 1, ng = N;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (A[i] + A[mid] > lim)
                ok = mid;
            else
                ng = mid;
        }
        if (ok < i)
            continue;
        M -= (ok - i) * 2 + 1;
        ans += (S[ok] - S[i]) * 2;
        ans += A[i] * ((ok - i) * 2LL + 2);
    }

    //! lim以下ででかいものから残っているっものだけ取得する
    cout << ans + lim * M << endl;
    return 0;
}