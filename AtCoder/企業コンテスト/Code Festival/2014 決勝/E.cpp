#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll R[3005];
ll dp[3005][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> R[i];
    }
    memset(dp, 0, sizeof(dp));
    REP(i, N) {
        dp[i][0] = dp[i][1] = 1;
        REP(j, i) {
            if (R[i] > R[j])
                dp[i][0] = std::max(dp[i][0], dp[j][1] + 1);
            if (R[i] < R[j])
                dp[i][1] = std::max(dp[i][1], dp[j][0] + 1);
        }
    }

    ll mx = 0;
    REP(i, N) {
        mx = std::max({mx, dp[i][0], dp[i][1]});
    }
    if (mx < 3)
        mx = 0;
    cout << mx << endl;
    return 0;
}