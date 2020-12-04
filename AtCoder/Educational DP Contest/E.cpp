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
    fill(dp[0], dp[105], INF);
    dp[0][0] = 0;
    REP(i, N) {
        REP(j, 100001) {
            dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);
            if (j + A[i].second <= 100000)
                dp[i + 1][j + A[i].second] = std::min(dp[i + 1][j + A[i].second], dp[i][j] + A[i].first);
        }
    }

    ll ans = 0;
    REP(i, 100001) {
        if (dp[N][i] <= W)
            ans = i;
    }
    cout << ans << endl;
    return 0;
}