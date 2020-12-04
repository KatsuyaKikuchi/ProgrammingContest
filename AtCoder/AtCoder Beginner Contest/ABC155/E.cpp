#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[1000010][2];

int main() {
    string S;
    cin >> S;
    ll N = S.length();
    reverse(S.begin(), S.end());
    ll index = 0;
    dp[0][0] = 0;
    dp[0][1] = 1;
    while (index < S.length()) {
        dp[index + 1][0] = dp[index][0] + S[index] - '0';
        if (S[index] != '9') {
            dp[index + 1][0] = std::min(dp[index + 1][0], dp[index][1] + S[index] - '0' + 1);
            dp[index + 1][1] = std::min(dp[index][0] + (10 - (S[index] - '0')) % 10,
                                        dp[index][1] + (9 - (S[index] - '0')));
        }
        else {
            dp[index + 1][0] = INF;
            dp[index + 1][1] = std::min(
                    dp[index][0] + (10 - (S[index] - '0')) % 10, dp[index][1] + (9 - (S[index] - '0')));
        }
        if (S[index] == '0')
            dp[index + 1][1]++;
        index++;
    }

    //! 最後に繰り上がり
    cout << std::min(dp[N][0], dp[N][1] + 1) << endl;
    return 0;
}