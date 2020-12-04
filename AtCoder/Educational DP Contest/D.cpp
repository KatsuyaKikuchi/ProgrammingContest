#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[105];
ll dp[105][100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, W;
    cin >> N >> W;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    REP(i, N) {
        REP(j, W + 1) {
            dp[i + 1][j] = std::max(dp[i][j], dp[i + 1][j]);
            if (j + A[i].first <= W)
                dp[i + 1][j + A[i].first] = std::max(dp[i + 1][j + A[i].first], dp[i][j] + A[i].second);
        }
    }

    ll ans = 0;
    REP(i, W + 1) {
        ans = std::max(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}