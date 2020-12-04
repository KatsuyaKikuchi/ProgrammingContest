#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

double dp[3005][3005];
double P[3005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> P[i];
    }

    dp[0][0] = 1;
    REP(i, N) {
        REP(j, N + 1) {
            dp[i + 1][j] += dp[i][j] * (1.0 - P[i]);
            if (j > 0)
                dp[i + 1][j] += dp[i][j - 1] * P[i];
        }
    }

    double ans = 0;
    FOR(i, N + 1, (N + 1) / 2) {
        ans += dp[N][i];
    }
    cout << OF64 << ans << endl;
    return 0;
}