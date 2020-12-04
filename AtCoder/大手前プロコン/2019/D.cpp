#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

//! [前からi桁目までで][j回発言した時の][3で割ったあまり]=通り数
ll dp[1005][1005][5];
ll F[1005];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        string S;
        cin >> S;
        if (S == "Fizz")
            F[i] = 0;
        else if (S == "Buzz")
            F[i] = 1;
        else
            F[i] = 2;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    REP(i, N) {
        REP(n, 10) {
            if (i == 0 && n == 0)
                continue;
            REP(k, 3) {
                ll s = (k + n) % 3;
                REP(j, std::min(M + 1, i + 1)) {
                    if (s != 0 && n != 5 && n != 0)
                        dp[i + 1][j][s] += dp[i][j][k];
                    dp[i + 1][j][s] %= MOD;
                    switch (F[j]) {
                        case 0:
                            if (s == 0 && n != 0 && n != 5)
                                dp[i + 1][j + 1][s] += dp[i][j][k];
                            break;
                        case 1:
                            if (s != 0 && (n == 0 || n == 5))
                                dp[i + 1][j + 1][s] += dp[i][j][k];
                            break;
                        case 2:
                            if (s == 0 && (n == 0 || n == 5))
                                dp[i + 1][j + 1][s] += dp[i][j][k];
                            break;
                    }
                    dp[i + 1][j + 1][s] %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    REP(i, 3) {
        ans = (ans + dp[N][M][i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}