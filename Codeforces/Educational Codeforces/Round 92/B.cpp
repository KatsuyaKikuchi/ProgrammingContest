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
    ll N, K, Z;
    cin >> N >> K >> Z;
    vector<ll> A(N);
    vector<vector<ll>> dp(N + 5, vector<ll>(Z + 5, 0));
    REP(i, N) {
        cin >> A[i];
    }
    dp[0][0] = A[0];
    REP(i, K) {
        REP(j, Z + 1) {
            ll index = i + 1 - j * 2;
            if (index >= 0) {
                dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j] + A[index]);
                if (index >= 1) {
                    dp[i + 2][j + 1] = std::max(dp[i + 2][j + 1], dp[i + 1][j] + A[index - 1]);
                    dp[i + 3][j + 1] = std::max(dp[i + 3][j + 1], dp[i + 2][j + 1] + A[index]);
                }
            }
        }
    }

    ll ans = 0;
    REP(i, Z + 1) {
        ans = std::max(ans, dp[K][i]);
    }
    return ans;
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