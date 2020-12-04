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
    ll P[3], Q[3];
    REP(i, 3) {
        cin >> P[i];
    }
    REP(i, 3) {
        cin >> Q[i];
    }
    vector<ll> v{0, 1, 2};
    ll ans = 0;
    do {
        ll x = 1;
        REP(i, 3) {
            x *= P[v[i]] / Q[i];
        }
        ans = std::max(ans, x);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}