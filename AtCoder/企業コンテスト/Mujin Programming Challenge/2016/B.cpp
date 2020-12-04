#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, C;
    cin >> A >> B >> C;
    ll mx = A + B + C;
    ll mn = std::max(0LL, 2 * std::max({A, B, C}) - mx);

    double ans = mx * mx * M_PI - mn * mn * M_PI;
    cout << OF64 << ans << endl;
    return 0;
}