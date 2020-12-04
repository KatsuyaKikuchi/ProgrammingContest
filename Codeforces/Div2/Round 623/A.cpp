#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(ll a, ll b, ll x, ll y) {

    ll n = x * b;
    ll m = (a - x - 1) * b;
    ll p = a * y;
    ll q = (b - y - 1) * a;
    return std::max({n, m, p, q});
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        cout << solve(a, b, x, y) << endl;
    }
    return 0;
}