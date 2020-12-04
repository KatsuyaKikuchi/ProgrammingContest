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
    ll X;
    cin >> X;
    ll ans = 1;
    FOR(i, X, 1) {
        ll n = i + 1;
        ll b = n * n;
        while (b <= X) {
            ans = std::max(ans, b);
            b *= n;
        }
    }
    cout << ans << endl;
    return 0;
}