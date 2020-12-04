#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll D[1005];
ll C[1005];
ll dp[1005][1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> D[i];
    }
    REP(i, M) {
        cin >> C[i];
    }

    REP(i, N + 1) {
        REP(j, M + 1) {
            dp[i][j] = INF;
        }
    }
    REP(j, M + 1) {
        dp[0][j] = 0;
    }
    REP(i, N) {
        REP(j, M) {
            dp[i + 1][j + 1] = std::min(dp[i][j] + D[i] * C[j], dp[i + 1][j]);
        }
    }

    cout << dp[N][M] << endl;
    return 0;
}