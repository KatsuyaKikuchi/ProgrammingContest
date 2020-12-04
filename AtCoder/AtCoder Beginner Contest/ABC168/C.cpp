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
    ll A, B, H, M;
    cin >> A >> B >> H >> M;

    double th0 = 6.0 * M;
    double th1 = 30.0 * H + 0.5 * M;
   // cout << th0 << " " << th1 << endl;

    double theta = abs(th0 - th1);
    double ans = sqrt(A * A + B * B - 2 * A * B * cos(theta / 180.0 * M_PI));

    cout << OF64 << ans << endl;
    return 0;
}