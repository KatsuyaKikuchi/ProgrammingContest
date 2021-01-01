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
    string S;
    cin >> S;
    ll N = S.length();

    if (N == 1) {
        return 0;
    }
    if (N == 2) {
        if (S[0] == S[1])
            return 1;
        return 0;
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(4, INF));
    if (S[0] == S[1]) {
        dp[2][1] = 1;
        dp[2][2] = 1;
        dp[2][3] = 2;
    }
    else {
        dp[2][0] = 0;
        dp[2][1] = 1;
        dp[2][2] = 1;
        dp[2][3] = 2;
    }
    FOR(i, N, 2) {
        if (S[i] == S[i - 1]) {
            if (S[i] == S[i - 2]) {
                //dp[i + 1][0] = std::min({dp[i][3], dp[i + 1][0]});
                dp[i + 1][1] = std::min({dp[i][0], dp[i][2]}) + 1;
                dp[i + 1][2] = std::min({dp[i][3], INF});
                dp[i + 1][3] = std::min({dp[i][3], dp[i][1]}) + 1;
            }
            else {
                //dp[i + 1][0] = std::min({dp[i][3], dp[i + 1][0]});
                dp[i + 1][1] = std::min({dp[i][0], dp[i][2]}) + 1;
                dp[i + 1][2] = std::min({dp[i][3], dp[i][1]});
                dp[i + 1][3] = std::min({dp[i][3], dp[i][1]}) + 1;
            }
        }
        else {
            if (S[i] == S[i - 2]) {
                dp[i + 1][0] = std::min({dp[i][2], dp[i + 1][0]});
                dp[i + 1][1] = std::min({dp[i][0], dp[i][2]}) + 1;
                dp[i + 1][2] = std::min({dp[i][3], INF});
                dp[i + 1][3] = std::min({dp[i][3], dp[i][1]}) + 1;
            }
            else {
                dp[i + 1][0] = std::min({dp[i][2], dp[i][0]});
                dp[i + 1][1] = std::min({dp[i][0], dp[i][2]}) + 1;
                dp[i + 1][2] = std::min({dp[i][3], dp[i][1]});
                dp[i + 1][3] = std::min({dp[i][3], dp[i][1]}) + 1;
            }
        }
    }

    return std::min({dp[N][0], dp[N][1], dp[N][2], dp[N][3]});
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