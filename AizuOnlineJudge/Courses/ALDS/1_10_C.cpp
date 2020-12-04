#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    string S, T;
    cin >> S >> T;
    ll N = S.length(), M = T.length();
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0));
    REP(i, N) {
        REP(j, M) {
            dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);
            if (S[i] == T[j])
                dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j] + 1);
        }
    }
    return dp[N][M];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}