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
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll ans = 0;
    for (ll y = B; y <= C; ++y) {
        ll a = std::max(C - y + 1, A);
        if (a > B)
            continue;
        ll a0 = std::min(a - (C - y), D - C + 1);
        ll s = std::min(B - a + 1, D - C + 1 - a0 + 1);
        ans += s * (2 * a0 + (s - 1)) / 2;
        ans += (D - C + 1) * (B - a + 1 - s);
    }
    cout << ans << endl;
    return 0;
}