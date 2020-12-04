#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(ll x, ll y, ll a, ll b) {
    ll z = y - x;
    ll c = a + b;
    if (z % c > 0)
        return -1;
    return z / c;
}

int main() {
    ll N;
    cin >> N;
    REP(_, N) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        cout << solve(x, y, a, b) << endl;
    }
    return 0;
}