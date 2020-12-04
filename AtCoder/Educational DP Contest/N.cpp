#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

ll A[405];
ll dp[405][405];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N + 3) {
        REP(j, N + 3) {
            dp[i][j] = INF;
        }
    }
    REP(i, N) {
        dp[i][i] = 0;
    }

    FOR(len, N + 1, 2) {
        REP(left, N) {
            if (left + len - 1 >= N)
                break;
            ll sum = 0;
            REP(j, len) {
                sum += A[left + j];
            }
            REP(j, len) {
                dp[left][left + len - 1]
                        = std::min(dp[left][left + len - 1],
                                   dp[left][left + j] + dp[left + j + 1][left + len - 1] + sum);
            }
        }
    }

    cout << dp[0][N - 1] << endl;
    return 0;
}