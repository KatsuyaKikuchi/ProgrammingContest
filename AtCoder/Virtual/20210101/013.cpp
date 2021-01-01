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
    ll N;
    cin >> N;
    ll a = 0, b = 0, c = 0;
    REP(i, N) {
        ll s, t, u;
        cin >> s >> t >> u;
        ll m = std::min({s, t, u});
        ll n = std::max({s, t, u});
        ll k = s + t + u - (m + n);
        a = std::max(a, m);
        b = std::max(b, k);
        c = std::max(c, n);
    }
    cout << a * b * c << endl;
    return 0;
}