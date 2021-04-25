#include <bits/stdc++.h>

using namespace std;

typedef unsigned long ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve(ll a, ll b, ll c) {
    ll x = 1;
    REP(i, b) {
        x *= c;
        if (x > a || x <= 0)
            return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b, c;
    cin >> a >> b >> c;
    if (solve(a, b, c))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}