#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[105][105][105];

int main() {
    ll N, M;
    cin >> N >> M;
    memset(dp, 0, sizeof(dp));
    REP(i, N) {
        ll a, b, c, w;
        cin >> a >> b >> c >> w;
        dp[a][b][c] = std::max(dp[a][b][c], w);
    }

    REP(i, 101) {
        REP(j, 101) {
            REP(k, 101) {
                ll m = 0;
                REP(p, 8) {
                    ll x = std::max(0LL, i - (p & 1));
                    ll y = std::max(0LL, j - ((p >> 1) & 1));
                    ll z = std::max(0LL, k - ((p >> 2) & 1));
                    m = std::max(m, dp[x][y][z]);
                }
                dp[i][j][k] = m;
            }
        }
    }

    REP(i, M) {
        ll x, y, z;
        cin >> x >> y >> z;
        cout << dp[x][y][z] << endl;
    }
    return 0;
}