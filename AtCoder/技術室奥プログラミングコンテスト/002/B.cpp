#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll V[505];
ll dp[505][505];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> V[i].first >> V[i].second;
    }
    memset(dp, 0, sizeof(dp));
    REP(i, N) {
        REP(j, M + 1) {
            dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);
            if (j - V[i].second >= 0)
                dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j - V[i].second] + V[i].first);
        }
    }
    ll max = 0;
    REP(i, M + 1) {
        max = std::max(dp[N][i], max);
    }
    cout << max << endl;
    return 0;
}