#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[105][105];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        REP(j, M) {
            cin >> A[i][j];
        }
    }

    ll ans = 0;
    REP(a, M) {
        FOR(b, M, a + 1) {
            ll s = 0;
            REP(i, N) {
                s += std::max(A[i][a], A[i][b]);
            }
            ans = std::max(ans, s);
        }
    }
    cout << ans << endl;
    return 0;
}