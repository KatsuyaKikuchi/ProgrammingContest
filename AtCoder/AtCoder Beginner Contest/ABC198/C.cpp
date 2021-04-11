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
    ll R, X, Y;
    cin >> R >> X >> Y;
    ll r = R * R;
    ll len = X * X + Y * Y;

    if (r == len) {
        cout << 1 << endl;
        return 0;
    }
    if (r > len) {
        cout << 2 << endl;
        return 0;
    }
    ll p = (len + r - 1) / r;
    ll ans = 0;
    while (true) {
        if (ans * ans >= p) {
            cout << ans << endl;
            break;
        }
        ans++;
    }
    return 0;
}