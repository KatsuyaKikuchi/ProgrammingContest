#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll CHAR = 26;
ll dp[200005][30];

int main() {
    string S;
    cin >> S;
    ll N = S.length();
    REP(i, CHAR) {
        dp[N][i] = 1;
    }

    for (ll i = N - 1; i >= 0; --i) {
        ll m = INF;
        REP(j, CHAR) {
            m = std::min(m, dp[i + 1][j]);
        }
        REP(j, CHAR) {
            dp[i][j] = dp[i + 1][j];
            if (S[i] - 'a' == j)
                dp[i][j]++;
            dp[i][j] = std::min(dp[i][j], m + 1);
        }
    }


    string ans = "";
    ll n = INF;
    REP(i, CHAR) {
        n = std::min(n, dp[0][i]);
    }
    ll index = 0;
    char c = 0;
    while (n > 0) {
        REP(j, CHAR) {
            if (dp[index][j] == n) {
                if (n > 1) {
                    while (S[index] - 'a' != j) {
                        index++;
                    }
                }
                ans.push_back((char) ('a' + j));
                n--;
                break;
            }
        }
        index++;
    }
    cout << ans << endl;
    return 0;
}