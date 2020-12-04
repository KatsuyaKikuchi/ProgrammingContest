#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
ll A[3005];
ll B[3005];
ll D[3005];
ll dp[3005][3005];

ll calc(ll n, ll m) {
    ll ok = -1, ng = N;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (D[mid] <= n)
            ok = mid;
        else
            ng = mid;
    }

    return std::min(ok + 1, m);
}

int main() {
    cin >> N;
    REP(i, N + 1) {
        cin >> A[i];
    }
    REP(i, N + 1) {
        cin >> B[i];
    }
    REP(i, N) {
        cin >> D[i];
    }
    sort(D, D + N);
    memset(dp, 0, sizeof(dp));

    ll ans = 0;
    dp[0][0] = N;
    REP(i, N + 1) {
        REP(j, N + 1) {
            if (i + j == 0)
                continue;
            if (i + j > N)
                break;

            ll p = A[i] + B[j];
            //! dp[i-1][j],dp[i][j-1]どちらかから遷移
            dp[i][j] = -1;
            if (i > 0) {
                //! dp[i-1][j]
                ll mi = -1;
                for (int k = dp[i - 1][j] - 1; k >= 0; --k) {
                    if (D[k] <= p) {
                        mi = k;
                        break;
                    }
                }
                dp[i][j] = std::max(dp[i][j], mi);
            }
            if (j > 0) {
                //! dp[i][j-1]
                ll mi = -1;
                for (int k = dp[i][j - 1] - 1; k >= 0; --k) {
                    if (D[k] <= p) {
                        mi = k;
                        break;
                    }
                }
                dp[i][j] = std::max(dp[i][j], mi);
            }

            //cout << dp[i][j] << " " << i << "," << j << endl;
            if (dp[i][j] >= 0) {
                ans = std::max(ans, i + j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}