#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll W[105];
bool dp[105][10005];

int main() {
    ll N;
    cin >> N;
    ll sum = 0;
    REP(i, N) {
        cin >> W[i];
        sum += W[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    REP(i, N) {
        REP(j, sum) {
            if (dp[i][j]) {
                dp[i + 1][j + W[i]] = true;
                dp[i + 1][j] = true;
            }
        }
    }

    if (sum % 2 == 0 && dp[N][sum / 2])
        cout << "possible" << endl;
    else
        cout << "impossible" << endl;
    return 0;
}