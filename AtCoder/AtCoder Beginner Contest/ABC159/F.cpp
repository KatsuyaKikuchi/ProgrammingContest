#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

ll A[3005];
ll dp[3005][3005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, S;
    cin >> N >> S;
    REP(i, N) {
        cin >> A[i];
    }

    memset(dp, 0, sizeof(dp));
    REP(i, N) {
        dp[i][0] = 1;
    }
    REP(i, N) {
        REP(j, S + 1) {
            dp[i + 1][j] += dp[i][j];
            if (j - A[i] >= 0)
                dp[i + 1][j] += dp[i][j - A[i]];
            dp[i + 1][j] %= MOD;
        }
    }

    ll ans = 0;
    REP(i, N) {
        ans = (ans + dp[i + 1][S]) % MOD;
    }
    cout << ans << endl;
    return 0;
}