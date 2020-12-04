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
    ll A, B, T;
    cin >> A >> B >> T;
    ll ans = 0;
    REP(i, 100) {
        ll a = (i + 1) * A;
        if (a > T)
            break;
        ans += B;

    }
    cout << ans << endl;
    return 0;
}