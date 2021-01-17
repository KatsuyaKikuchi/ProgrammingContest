#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[105][105];

ll solve(string &s, string &t) {
    ll N = s.length(), M = t.length();
    memset(dp, 0, sizeof(dp));
    REP(i, N) {
        REP(j, M) {
            dp[i + 1][j + 1] = std::max({dp[i][j + 1], dp[i + 1][j], dp[i][j]});
            if (s[i] == t[j])
                dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j] + 1);
        }
    }
    return dp[N][M];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll ans = N;
    REP(i, N + 1) {
        string left = "", right = "";
        REP(j, i) {
            left.push_back(S[j]);
        }
        FOR(j, N, i) {
            right.push_back(S[j]);
        }
        ans = std::min(ans, N - 2LL * solve(left, right));
    }
    cout << ans << endl;
    return 0;
}