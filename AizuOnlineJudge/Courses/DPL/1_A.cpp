#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[30];
ll dp[25][50005];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        cin >> C[i];
    }
    REP(i, M + 1) {
        REP(j, N + 1) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    REP(i, M) {
        REP(j, N + 1) {
            dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);
            if (j - C[i] >= 0) {
                dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j - C[i]] + 1);
                dp[i + 1][j] = std::min(dp[i + 1][j], dp[i + 1][j - C[i]] + 1);
            }
        }
    }
    cout << dp[M][N] << endl;
    return 0;
}