#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[10005];
int dp[10005][1005];

int main() {
    ll N, M, L, X;
    cin >> N >> M >> L >> X;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N + 1) {
        REP(j, M) {
            dp[i][j] = X;
        }
    }
    dp[0][0] = 1;
    REP(i, N) {
        REP(j, M) {
            dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);
            ll p = j + A[i];
            int n = dp[i][j] + p / M;
            dp[i + 1][p % M] = std::min(n, dp[i + 1][p % M]);
        }
    }

    if (dp[N][L] < X)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}