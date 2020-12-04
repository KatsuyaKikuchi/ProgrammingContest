#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 10007;
const ll INF = (ll) 1e15;

ll dp[1005][8];

ll get(char c) {
    if (c == 'J')
        return 0;
    if (c == 'O')
        return 1;
    return 2;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    REP(i, N) {
        ll n = get(S[i]);
        REP(j, 8) {
            if (((j >> n) & 1) == 0)
                continue;
            REP(k, 8) {
                if ((j & k) > 0)
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][k]) % MOD;
            }
        }
    }

    ll ans = 0;
    REP(i, 8) {
        ans += dp[N][i];
    }
    cout << ans % MOD << endl;
    return 0;
}