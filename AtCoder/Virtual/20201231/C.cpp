#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[1000005][20];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.length();
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    REP(i, N) {
        REP(j, 13) {
            if (S[i] == '?') {
                REP(k, 10) {
                    ll nxt = (j * 10 + k) % 13;
                    dp[i + 1][nxt] += dp[i][j];
                    dp[i + 1][nxt] %= MOD;
                }
            }
            else {
                ll nxt = (j * 10 + S[i] - '0') % 13;
                dp[i + 1][nxt] += dp[i][j];
                dp[i + 1][nxt] %= MOD;
            }
        }
    }
    cout << dp[N][5] << endl;
    return 0;
}