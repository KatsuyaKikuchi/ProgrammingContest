#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll solve(ll X, ll Y) {
    if (X == 0 && Y == 0)
        return pll(1, 1);
    if (X == 0)
        return pll(2 * Y, Y);
    if (Y == 0)
        return pll(X, 2 * X);
    {
        ll a = X;
        ll b = X + Y;
        if (a % b == X && b % a == Y)
            return pll(a, b);
    }
    {
        ll a = X + Y;
        ll b = Y;
        if (a % b == X && b % a == Y)
            return pll(a, b);
    }
    return pll(-1, -1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll X, Y;
    cin >> X >> Y;
    pll ans = solve(X, Y);
    if (ans.first < 0)
        cout << -1 << endl;
    else
        cout << ans.first << " " << ans.second << endl;
    return 0;
}