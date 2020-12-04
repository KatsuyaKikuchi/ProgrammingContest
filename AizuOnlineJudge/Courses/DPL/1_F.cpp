#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[105][10005];
pll V[105];

int main() {
    ll N, W;
    cin >> N >> W;
    REP(i, N) {
        cin >> V[i].first >> V[i].second;
    }

    std::fill(dp[0], dp[105], INF);
    dp[0][0] = 0;
    ll max = 0;
    REP(i, N) {
        REP(j, max + 1) {
            dp[i + 1][j] = std::min(dp[i][j], dp[i + 1][j]);
            ll w = dp[i][j] + V[i].second;
            if (w <= W) {
                dp[i + 1][j + V[i].first] = std::min(dp[i + 1][j + V[i].first], w);
                max = std::max(max, V[i].first + j);
            }
        }
    }

    cout << max << endl;
    return 0;
}