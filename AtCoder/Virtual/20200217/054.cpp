#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

ll T[105];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> T[i];
    }
    ll ans = T[0];
    REP(i, N) {
        ll g = gcd(ans, T[i]);
        ans = (ans / g) * T[i];
    }
    cout << ans << endl;
    return 0;
}