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
    cin.tie(0);
    ios::sync_with_stdio(false);
    pll c;
    ll r;
    cin >> c.first >> c.second >> r;
    pll x, y;
    cin >> x.first >> x.second >> y.first >> y.second;

    bool red = false, blue = false;
    if (r + c.first > y.first || c.first - r < x.first ||
        r + c.second > y.second || c.second - r < x.second)
        red = true;

    if (pow(c.first - x.first, 2) + pow(c.second - x.second, 2) > r * r ||
        pow(c.first - x.first, 2) + pow(c.second - y.second, 2) > r * r ||
        pow(c.first - y.first, 2) + pow(c.second - y.second, 2) > r * r ||
        pow(c.first - y.first, 2) + pow(c.second - x.second, 2) > r * r)
        blue = true;

    if (red)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    if (blue)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}