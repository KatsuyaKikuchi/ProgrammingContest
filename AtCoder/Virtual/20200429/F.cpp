#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = (ll) (80 * 80 * 10);
pll G[85][85];
bool dp[85][85][MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> G[i][j].first;
        }
    }
    REP(i, H) {
        REP(j, W) {
            cin >> G[i][j].second;
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = dp[1][0][0] = dp[0][1][0] = true;
    REP(i, H) {
        REP(j, W) {
            ll d = abs(G[i][j].first - G[i][j].second);
            REP(n, MAX) {
                if (dp[i + 1][j][n] || dp[i][j + 1][n]) {
                    dp[i + 1][j + 1][n + d] = dp[i + 1][j + 1][abs(n - d)] = true;
                }
            }
        }
    }

    REP(i, MAX) {
        if (dp[H][W][i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}