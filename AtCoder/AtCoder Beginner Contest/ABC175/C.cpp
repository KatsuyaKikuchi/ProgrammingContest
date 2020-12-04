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
    ll X, K, D;
    cin >> X >> K >> D;

    ll x = abs(X) / D;
    ll t = std::min(K, x);
    K -= t;
    X = abs(X) - D * t;

    ll ans = X;
    if (K % 2 == 1) {
        ans = std::min(abs(X + D), abs(X - D));
    }

    cout << ans << endl;
    return 0;
}