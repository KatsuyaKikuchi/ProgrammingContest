#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[2005];
ll dp[2005][2005];
ll SH[2005][2005];
ll SR[2005][2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    memset(dp, 0, sizeof(dp));
    memset(SH, 0, sizeof(SH));
    memset(SR, 0, sizeof(SR));
    dp[0][0] = 1;
    REP(i, H) {
        ll s = 0;
        REP(j, W) {
            if (S[i][j] == '#') {
                SH[i][j] = 0;
                SR[i][j] = 0;
                s = 0;
            }
            dp[i][j] += (s + SH[i][j] + SR[i][j]) % MOD;
            dp[i][j] %= MOD;
            s += dp[i][j];
            s %= MOD;
            SH[i + 1][j] = (SH[i][j] + dp[i][j]) % MOD;
            SR[i + 1][j + 1] = (SR[i][j] + dp[i][j]) % MOD;
        }
    }
#if false
    REP(i, H) {
        REP(j, W) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
#endif
    cout << dp[H - 1][W - 1] % MOD << endl;
    return 0;
}