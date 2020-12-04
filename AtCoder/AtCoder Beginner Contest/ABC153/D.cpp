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
    ll H;
    cin >> H;
    ll ans = 0;

    ll t = 1;
    while (H > 0) {
        H /= 2LL;
        ans += t;
        t *= 2LL;
    }
    cout << ans << endl;
    return 0;
}