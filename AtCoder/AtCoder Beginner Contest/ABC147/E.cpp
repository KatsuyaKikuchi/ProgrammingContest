#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

const ll MAX = 15000;

ll A[100][100];
ll B[100][100];

bool dp[85][85][MAX];

int main() {
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }
    REP(i, H) {
        REP(j, W) {
            cin >> B[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0][abs(A[0][0] - B[0][0])] = true;
    REP(i, H) {
        REP(j, W) {
            ll d = abs(A[i][j] - B[i][j]);
            REP(n, MAX) {
                if (i > 0 && dp[i - 1][j][n]) {
                    //! 上
                    if (abs(n - d) < MAX)
                        dp[i][j][abs(n - d)] = true;
                    if (n + d < MAX)
                        dp[i][j][n + d] = true;
                }
                if (j > 0 && dp[i][j - 1][n]) {
                    //! 左
                    if (abs(n - d) < MAX)
                        dp[i][j][abs(n - d)] = true;
                    if (n + d < MAX)
                        dp[i][j][n + d] = true;
                }
            }
        }
    }

    REP(i, MAX) {
        if (dp[H - 1][W - 1][i]) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}