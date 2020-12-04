#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[1005][1005];

int main() {
    string S, T;
    cin >> S >> T;
    ll N = S.length(), M = T.length();
    REP(i, N + 1) {
        REP(j, M + 1) {
            dp[i][j] = INF;
        }
    }
    REP(i, N + 1) {
        dp[i][0] = i;
    }
    REP(j, M + 1) {
        dp[0][j] = j;
    }

    REP(i, N) {
        REP(j, M) {
            dp[i + 1][j + 1] = std::min(dp[i][j], std::min(dp[i + 1][j], dp[i][j + 1])) + 1;
            if (S[i] == T[j])
                dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j]);
        }
    }
    cout << dp[N][M] << endl;
    return 0;
}