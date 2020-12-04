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

ll modpow(ll n, ll r) {
    ll ret = 1;
    ll p = n;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % MOD;
        p = (p * p) % MOD;
        r >>= 1;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, S;
    cin >> N >> S;

    REP(i, N) {
        cin >> A[i];
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    REP(i, N) {
        REP(j, S + 1) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            if (j + A[i] <= S)
                dp[i + 1][j + A[i]] = (dp[i + 1][j + A[i]] + dp[i][j]) % MOD;
        }
    }

    ll ans = 0;
    REP(i, N) {
        cout << dp[i + 1][S] << endl;
        ans += dp[i + 1][S] * modpow(2, N - (i - 1)) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}