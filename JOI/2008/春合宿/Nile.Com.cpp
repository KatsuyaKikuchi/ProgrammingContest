#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[400][3005];
ll dp[400][3005][5];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, D;
    cin >> N >> D;
    REP(i, D) {
        REP(j, N) {
            cin >> A[i][j];
        }
    }

    REP(i, N + 1) {
        dp[0][i][0] = dp[0][i][1] = dp[0][i][2] = INF;
    }
    ll min = 0;
    REP(i, D) {
        ll m = INF;
        REP(j, N) {
            dp[i + 1][j][0] = min + A[i][j];
            dp[i + 1][j][1] = dp[i][j][0] + A[i][j] * 9 / 10;
            dp[i + 1][j][2] = std::min(dp[i][j][1], dp[i][j][2]) + A[i][j] * 7 / 10;

            m = std::min({dp[i + 1][j][0], dp[i + 1][j][1], dp[i + 1][j][2], m});
        }
        min = m;
    }

    cout << min << endl;
    return 0;
}