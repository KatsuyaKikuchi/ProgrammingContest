#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

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
    dp[0][1] = dp[0][0] = 1;
    FOR(i, N, 1) {
        REP(j, i) {
            if (R[j] < R[i]) {
                dp[i][0] = std::max(dp[i][0], dp[j][1] + 1);
            }
            else if (R[j] > R[i]) {
                dp[i][1] = std::max(dp[i][1], dp[j][0] + 1);
            }
        }
    }

    ll m = std::max(dp[N - 1][0], dp[N - 1][1]);
    if (m < 3)
        m = 0;
    cout << m << endl;
    return 0;
}