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
ll dp[105][405][105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, W;
    cin >> N >> W;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    memset(dp, 0, sizeof(dp));
    REP(i, N) {
        REP(j, 4 * N + 1) {
            REP(k, N + 1) {
                dp[i + 1][j][k] = std::max(dp[i + 1][j][k], dp[i][j][k]);
                ll d = A[i].first - A[0].first;
                ll w = k * A[0].first + j + A[i].first;
                if (w <= W) {
                    dp[i + 1][j + d][k + 1] = std::max(dp[i + 1][j + d][k + 1], dp[i][j][k] + A[i].second);
                }
            }
        }
    }

    ll ans = 0;
    REP(i, 4 * N + 1) {
        REP(j, N + 1) {
            ans = std::max(ans, dp[N][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}