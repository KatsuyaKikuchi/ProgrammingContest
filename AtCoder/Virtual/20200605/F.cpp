#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[100005][5][5];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.length();
    memset(dp, 0, sizeof(dp));
    ll p = 1;
    REP(i, N) {
        REP(j, 3) {
            REP(n, 3) {
                if (S[i] != '?' && S[i] - 'A' != n)
                    continue;
                REP(t, 3) {
                    dp[i + 1][n][j] += dp[i][t][j];
                }
                dp[i + 1][n][j] %= MOD;
            }
        }
        REP(j, 3) {
            if (S[i] != '?' && S[i] - 'A' != j)
                continue;

            if (j == 0) {
                dp[i + 1][0][0] += p;
            }
            if (j == 1) {
                REP(t, 3) {
                    dp[i + 1][1][1] += dp[i][t][0];
                }
            }
            if (j == 2) {
                REP(t, 3) {
                    dp[i + 1][2][2] += dp[i][t][1];
                }
            }
            dp[i + 1][j][j] %= MOD;
        }
        if (S[i] == '?')
            p = (p * 3LL) % MOD;
    }

#if false
    REP(i, N) {
        REP(j, 3) {
            REP(k, 3) {
                cout << dp[i + 1][j][k] << " ";
            }
            cout << endl;
        }
        cout << "--------" << endl;
    }
#endif


    ll ans = dp[N][0][2] + dp[N][1][2] + dp[N][2][2];
    cout << ans % MOD << endl;
    return 0;
}