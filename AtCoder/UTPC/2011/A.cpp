#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll M, N;
    cin >> M >> N;
    ll ans = 0;
    REP(i, M) {
        ll m = 0;
        REP(j, N) {
            ll a;
            cin >> a;
            m += a;
        }
        ans = std::max(ans, m);
    }
    cout << ans << endl;
    return 0;
}