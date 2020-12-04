#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[105][10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, K;
    cin >> H >> W >> K;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    ll p = pow(2LL, W - 1);
    REP(i, H) {
        REP(b, p) {
            bool e = true;
            REP(j, W - 1) {
                if ((b >> j) & (b >> (j + 1)) & 1) {
                    e = false;
                    break;
                }
            }
            if (!e)
                continue;

            REP(j, W) {
                if (j > 0 && ((b >> (j - 1)) & 1))
                    dp[i + 1][j] += dp[i][j - 1];
                else if (j < W - 1 && ((b >> j) & 1))
                    dp[i + 1][j] += dp[i][j + 1];
                else
                    dp[i + 1][j] += dp[i][j];
            }
        }
        REP(j, W) {
            dp[i + 1][j] %= MOD;
        }
    }

    cout << dp[H][K - 1] << endl;
    return 0;
}