#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H[100005];
ll dp[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> H[i];
    }
    REP(i, N) {
        dp[i] = INF;
    }
    dp[0] = 0;
    REP(i, N) {
        if (i + 1 < N)
            dp[i + 1] = std::min(dp[i + 1], dp[i] + abs(H[i + 1] - H[i]));
        if (i + 2 < N)
            dp[i + 2] = std::min(dp[i + 2], dp[i] + abs(H[i + 2] - H[i]));
    }
    cout << dp[N - 1] << endl;
    return 0;
}