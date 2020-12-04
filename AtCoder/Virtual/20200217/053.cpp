#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[205][205];

int main() {
    ll N, M, R;
    cin >> N >> M >> R;
    vector<ll> r(R);
    REP(i, R) {
        cin >> r[i];
        r[i]--;
    }

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

    sort(r.begin(), r.end());
    ll ans = INF;
    do {
        ll c = 0;
        REP(i, R - 1) {
            c += C[r[i]][r[i + 1]];
        }
        ans = std::min(ans, c);
    } while (next_permutation(r.begin(), r.end()));
    cout << ans << endl;

    return 0;
}