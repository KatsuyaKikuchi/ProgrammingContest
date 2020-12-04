#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 13;

ll dp[100005][15];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.length();
    reverse(S.begin(), S.end());
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    ll d = 1;
    REP(i, N) {
        REP(j, MAX) {
            REP(n, 10) {
                if (S[i] != '?' && S[i] != '0' + n)
                    continue;
                ll m = (n * d + j) % MAX;
                dp[i + 1][m] += dp[i][j];
                dp[i + 1][m] %= MOD;
            }
        }
        d = d * 10LL % MAX;
    }
    cout << dp[N][5] << endl;
    return 0;
}