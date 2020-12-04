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
    ll X;
    cin >> X;
    ll T = X % 100;
    ll f = T / 5;
    ll a = 0;
    if (T % 5 != 0)
        a = 1;

    ll S = (f + a) * 100;
    if (S <= X)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}