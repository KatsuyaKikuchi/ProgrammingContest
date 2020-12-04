#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1e5;
const ll INF = (ll) 1e15;

ll dp[105][105][105][2];
ll x[2] = {0, -1};
ll y[2] = {-1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = dp[0][0][0][1] = 1;
    REP(h, H) {
        REP(w, W) {
            REP(n, 2) {
                ll ph = h + x[n], pw = w + y[n];
                if (ph < 0 || pw < 0)
                    continue;
                REP(i, std::max(H, W)) {
                    {
                        ll p = dp[ph][pw][i][n];
                        dp[h][w][i + 1][n] += p;
                    }
                    {
                        ll p = dp[ph][pw][i + 1][(n + 1) % 2];
                        dp[h][w][0][n] += p;
                    }
                }
                dp[h][w][0][(n + 1) % 2] %= MOD;
            }
        }
    }

    ll ans = 0;
    REP(i, 100) {
        ans += dp[H - 1][W - 1][i][0] + dp[H - 1][W - 1][i][1];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}