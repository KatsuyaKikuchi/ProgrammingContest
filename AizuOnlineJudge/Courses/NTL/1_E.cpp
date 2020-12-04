#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

ll gcdex(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = gcdex(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll c = gcd(a, b);

    ll x, y;
    gcdex(a, b, x, y);
    cout << x << " " << y << endl;
    return 0;
}