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
    ll X, Y;
    cin >> X >> Y;
    ll x = X;
    ll ans = 0;
    while (x <= Y) {
        x *= 2LL;
        ans++;
    }
    cout << ans << endl;
    return 0;
}