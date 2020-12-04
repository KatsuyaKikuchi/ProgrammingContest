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
    ll H, W;
    cin >> H >> W;
    if (H == 1 || W == 1) {
        cout << 1 << endl;
        return 0;
    }

    ll A = (W + 1) / 2;
    ll ans = ((H + 1) / 2) * A + (H / 2) * (W - A);
    cout << ans << endl;
    return 0;
}