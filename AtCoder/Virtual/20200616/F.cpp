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
ll dp[305][305][305];

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
        REP(x, X + 1) {
            REP(y, Y + 1) {
                dp[i + 1][x][y] = std::max(dp[i + 1][x][y], dp[i][x][y]);
                ll t = A[i].first;
                if (x + y + t > X + Y)
                    continue;
                ll c = A[i].second;

                ll ny = std::min(Y - y, t - 1);
                t -= ny;
                ll nx = t;
                if (nx > X - x)
                    continue;
                dp[i + 1][x + nx][y + ny] = std::max(dp[i][x][y] + c, dp[i + 1][x + nx][y + ny]);
            }
        }
    }

#if false
    REP(i, N) {
        REP(x, X + 1) {
            REP(y, Y + 1) {
                cout << dp[i + 1][x][y] << " ";
            }
            cout << endl;
        }
        cout << "----------------------" << endl;
    }
#endif

    ll ans = 0;
    REP(x, X + 1) {
        REP(y, Y + 1) {
            ans = std::max(ans, dp[N][x][y]);
        }
    }
    cout << ans << endl;
    return 0;
}