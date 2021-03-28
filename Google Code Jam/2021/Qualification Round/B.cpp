#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll X, Y;
    cin >> X >> Y;
    string S;
    cin >> S;
    ll N = S.length();

    vector<vector<ll>> dp(N + 1, vector<ll>(2, INF));
    if (S[0] == 'C') {
        dp[1][0] = 0;
    }
    else if (S[0] == 'J') {
        dp[1][1] = 0;
    }
    else {
        dp[1][0] = 0;
        dp[1][1] = 0;
    }
    FOR(i, N, 1) {
        if (S[i] != 'J') {
            dp[i + 1][0] = std::min(dp[i][0], dp[i][1] + Y);
        }
        if (S[i] != 'C') {
            dp[i + 1][1] = std::min(dp[i][1], dp[i][0] + X);
        }
    }

    return std::min(dp[N][0], dp[N][1]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(i, Q) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}