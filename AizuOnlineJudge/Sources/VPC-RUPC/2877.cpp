#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[505];
double dp[510][510];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }

    REP(i, N + 5) {
        REP(j, N + 5) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    REP(i, N) {
        double sum = 0;
        FOR(j, N, i) {
            sum += A[j];
            double num = j + 1 - i;
            REP(m, M) {
                dp[j + 1][m + 1] = std::max(dp[j + 1][m + 1], dp[i][m] + sum / num);
            }
        }
    }

    double ans = 0;
    REP(i, M) {
        ans = std::max(ans, dp[N][i + 1]);
    }
    cout << OF64 << ans << endl;
    return 0;
}