#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

ll dp[3005][3005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;

    memset(dp, 0, sizeof(dp));

    dp[0][T.size()] = 1;
    REP(i, S.length()) {
        REP(j, T.size()) {
            if (j < T.size() && S[i] == T[j]) {
                dp[i + 1][j] += dp[i][j + 1] + 1;
                dp[i + 1][j] %= MOD;
            }
            if (j - i >= 0) {
                dp[i + 1][j - i] += dp[i][j - i] + 1;
                dp[i + 1][j - i] %= MOD;
            }
        }
    }

    ll ans = 0;
    REP(i, S.length()) {
        ans = (ans + dp[i + 1][0]) % MOD;
    }
    cout << ans << endl;
    return 0;
}