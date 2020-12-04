#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[505][505];
ll B[505][505];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        REP(j, M) {
            cin >> A[i][j];
        }
    }
    REP(i, N) {
        REP(j, M) {
            cin >> B[i][j];
        }
    }

    ll t = 0;
    REP(i, N) {
        ll m = INF;
        REP(j, M) {
            ll s = ((t + A[i][j] - 1) / A[i][j]) * A[i][j];
            m = std::min(m, s + B[i][j]);
        }
        t = m;
    }
    cout << t << endl;
    return 0;
}