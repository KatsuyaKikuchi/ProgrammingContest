#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[305][305];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        REP(j, N) {
            C[i][j] = INF;
        }
        C[i][i] = 0;
    }

    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        C[a][b] = C[b][a] = std::min({C[a][b], C[b][a], c});
    }

    REP(k, N) {
        REP(i, N) {
            REP(j, N) {
                C[i][j] = std::min(C[i][j], C[i][k] + C[k][j]);
            }
        }
    }

    ll ans = INF;
    REP(i, N) {
        ll m = 0;
        REP(j, N) {
            m = std::max(m, C[i][j]);
        }
        ans = std::min(ans, m);
    }
    cout << ans << endl;
    return 0;
}