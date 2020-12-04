#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(50)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    double L;
    cin >> L;
    double T = 2.0 * L / 3.0;

    double ans = T * (L - T) * (L - T) / 2.0;
    cout << OF64 << ans << endl;
    return 0;
}