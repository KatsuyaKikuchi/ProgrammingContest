#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[3005][3005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S, T;
    cin >> S >> T;
    memset(dp, 0, sizeof(dp));
    REP(i, S.length()) {
        REP(j, T.length()) {
            if (S[i] == T[j])
                dp[i + 1][j + 1] = std::max({dp[i + 1][j], dp[i][j] + 1, dp[i][j + 1]});
            else
                dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    string ans = "";
    {
        ll i = S.length(), j = T.length();
        while (i > 0 && j > 0 && dp[i][j] > 0) {
            ll a = i, b = j;
            while (dp[a][b] == dp[i - 1][j])
                i--;
            while (dp[a][b] == dp[i][j - 1])
                j--;
            ans.push_back(S[i - 1]);
            i--;
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}