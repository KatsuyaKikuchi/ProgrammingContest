#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

long double P[505], Q[505];
long double dp[505][505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> P[i];
    }
    REP(i, N + 1) {
        cin >> Q[i];
    }

    REP(i, N + 1) {
        REP(j, N + 1) {
            dp[i][j] = INF;
        }
    }

    REP(len, N) {
        REP(left, N) {
            if (left + len >= N)
                break;

            long double sum = Q[left + len + 1];
            REP(i, len + 1) {
                sum += P[left + i] + Q[left + i];
            }
            REP(i, len + 1) {
                //! 頂点iをroot
                long double p = sum;
                if (i == 0)
                    p += Q[left + i];
                else
                    p += dp[left][left + i - 1];

                if (i == len)
                    p += Q[left + i + 1];
                else
                    p += dp[left + i + 1][left + len];

                dp[left][left + len] = std::min(dp[left][left + len], p);
            }
        }
    }

    cout << OF64 << dp[0][N - 1] << endl;
    return 0;
}