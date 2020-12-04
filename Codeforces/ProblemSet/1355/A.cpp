#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll A, K;
    cin >> A >> K;
    REP(i, K - 1) {
        ll mx = 0, mn = 10;
        ll t = A;
        while (t > 0) {
            ll m = t % 10;
            mx = std::max(mx, m);
            mn = std::min(mn, m);
            t /= 10;
        }
        A += mx * mn;
        if (mn == 0)
            break;
    }
    return A;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        cout << solve() << endl;
    }
    return 0;
}