#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[3005];
ll dp[3005][3005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    memset(dp, 0, sizeof(dp));
    if (N % 2 == 1) {
        REP(i, N) {
            dp[i][i] = A[i];
        }
    }
    FOR(len, N, 1) {
        REP(i, N) {
            if (i + len >= N)
                break;
            if (len % 2 == N % 2) {
                //! second
                dp[i][i + len] = std::min(dp[i][i + len - 1], dp[i + 1][i + len]);
            }
            else {
                //! firts
                dp[i][i + len] = std::max(dp[i][i + len - 1] + A[i + len], dp[i + 1][i + len] + A[i]);
            }
        }
    }

    ll sum = 0;
    REP(i, N) {
        sum += A[i];
    }
    ll mx = dp[0][N - 1];
    cout << mx - (sum - mx) << endl;
    return 0;
}