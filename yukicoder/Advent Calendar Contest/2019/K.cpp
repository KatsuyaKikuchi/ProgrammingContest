#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(30)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    double r, R;
    cin >> r >> R;
    double theta = asin(r / R) * 2;

    double ans = ((R + r) * (R + r) - (R - r) * (R - r)) * M_PI * ((2 * M_PI - theta) / (2 * M_PI)) + r * r * M_PI;
    cout << OF64 << 2 * M_PI - theta << endl;
    cout << OF64 << ans << endl;
    return 0;
}