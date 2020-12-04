#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[2005][2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll S;
    cin >> S;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    ll ans = 0;
    REP(i, S) {
        if ((i + 1) * 3LL > S)
            break;
        FOR(j, S + 1, i * 3) {
            FOR(k, S + 1, 3) {
                if (k + j > S)
                    break;
                dp[i + 1][k + j] += dp[i][j];
                dp[i + 1][k + j] %= MOD;
            }
        }

        ans = (ans + dp[i + 1][S]) % MOD;
    }
    cout << ans << endl;
    return 0;
}