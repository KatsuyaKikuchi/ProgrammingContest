#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[305];
ll dp[2][605][305];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll X, Y, N;
    cin >> X >> Y >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    memset(dp, 0, sizeof(dp));
    REP(i, N) {
        REP(j, X + Y + 1) {
            REP(k, N + 1) {
                dp[1][j][k] = std::max(dp[1][j][k], dp[0][j][k]);
            }
            if (j + A[i].first > X + Y)
                continue;
            REP(k, N + 1) {
                ll d = X - k - std::max(0LL, j - k - Y);
                if (d > 0) {
                    dp[1][j + A[i].first][k + 1] = std::max(dp[1][j + A[i].first][k + 1],
                                                            dp[0][j][k] + A[i].second);
                }
            }
        }
        swap(dp[0], dp[1]);
    }

#if false
    REP(i, N) {
        REP(j, X + Y + 1) {
            REP(k, N + 1) {
                cout << dp[i + 1][j][k] << " ";
            }
            cout << endl;
        }
        cout << "--------------" << endl;
    }
#endif

    ll ans = 0;
    REP(i, N) {
        REP(j, X + Y) {
            ans = std::max(dp[0][j + 1][i + 1], ans);
        }
    }
    cout << ans << endl;
    return 0;
}