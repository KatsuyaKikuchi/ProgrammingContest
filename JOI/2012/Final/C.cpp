#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef pair<int, int> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[3005];
ll dp0[3005][3005];
ll dp1[3005][3005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, T, S;
    cin >> N >> T >> S;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    memset(dp0, 0, sizeof(dp0));
    memset(dp1, 0, sizeof(dp1));

    REP(i, N) {
        REP(j, T + 1) {
            dp0[i + 1][j] = std::max(dp0[i + 1][j], dp0[i][j]);
            if (j - A[i].second >= 0)
                dp0[i + 1][j] = std::max(dp0[i + 1][j], dp0[i][j - A[i].second] + A[i].first);
        }
    }
    for (ll i = N - 1; i >= 0; --i) {
        REP(j, T + 1) {
            dp1[i][j] = std::max(dp1[i][j], dp1[i + 1][j]);
            if (j - A[i].second >= 0)
                dp1[i][j] = std::max(dp1[i][j], dp1[i + 1][j - A[i].second] + A[i].first);
        }
    }

    ll ans = 0;
    ll T0 = S, T1 = T - S;
    REP(i, N + 1) {
        ll m0 = 0, m1 = 0;
        REP(j, T0 + 1) {
            m0 = std::max(m0, dp0[i][j]);
        }
        REP(j, T1 + 1) {
            m1 = std::max(m1, dp1[i][j]);
        }
        ans = std::max(ans, m0 + m1);
    }
    cout << ans << endl;
    return 0;
}