#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[1005];
ll dp[1005][10005];

int main() {
    ll H, N;
    cin >> H >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    REP(i, N + 1) {
        REP(j, H + 1) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    REP(i, N) {
        REP(j, H + 1) {
            dp[i + 1][j] = std::min(dp[i][j], dp[i + 1][j]);
            ll t = std::min(j + A[i].first, H);
            dp[i + 1][t] = std::min(dp[i + 1][t], dp[i][j] + A[i].second);
            dp[i + 1][t] = std::min(dp[i + 1][t], dp[i + 1][j] + A[i].second);

        }
    }

    cout << dp[N][H] << endl;
    return 0;
}