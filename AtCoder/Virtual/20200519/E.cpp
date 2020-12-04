#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[105][5][5][5];
ll A = 0, G = 1, C = 2, T = 3;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    memset(dp, 0, sizeof(dp));
    REP(i, 4) {
        REP(j, 4) {
            REP(k, 4) {
                if ((i == A && j == G && k == C) ||
                    (i == A && j == C && k == G) ||
                    (i == G && j == A && k == C))
                    continue;
                dp[3][i][j][k] = 1;
            }
        }
    }
    FOR(i, N, 3) {
        REP(n, 4) {
            REP(p0, 4) {
                REP(p1, 4) {
                    REP(p2, 4) {
                        if ((p1 == A && p0 == C && n == G) ||
                            (p1 == A && p0 == G && n == C) ||
                            (p1 == G && p0 == A && n == C) ||
                            (p2 == A && p1 == G && n == C) ||
                            (p2 == A && p0 == G && n == C))
                            continue;

                        dp[i + 1][p1][p0][n] += dp[i][p2][p1][p0];
                        dp[i + 1][p1][p0][n] %= MOD;
                    }
                }
            }
        }
    }

    ll ans = 0;
    REP(i, 4) {
        REP(j, 4) {
            REP(k, 4) {
                ans += dp[N][i][j][k];
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;

    return 0;
}