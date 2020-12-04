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
    ll H, W, x, y;
    cin >> H >> W >> x >> y;
    double s = H * W * 0.5;

    cout << OF64 << s << " ";
    if (x * 2 == H && y * 2 == W)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}