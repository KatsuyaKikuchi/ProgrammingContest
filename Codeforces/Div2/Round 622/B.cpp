#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve(ll n, ll x, ll y) {
    if (x > y)
        swap(x, y);
    ll s = x + y;
    ll a = n;
    {
        ll ng = 0;
        while (abs(a - ng) > 1) {
            ll mid = (a + ng) / 2;
            if (mid + n > s)
                a = mid;
            else
                ng = mid;
        }
    }
    ll b = std::min(s - 1, n);

    cout << a << " " << b << endl;
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll n, x, y;
        cin >> n >> x >> y;
        solve(n, x, y);
    }
    return 0;
}