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
    ll I, O, T, J, L, S, Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;
    ll ans = O + (I / 2 + J / 2 + L / 2) * 2LL;
    if (I > 0 && J > 0 && L > 0) {
        I--;
        J--;
        L--;
        ans = std::max({ans, O + (I / 2 + J / 2 + L / 2) * 2LL + 3});
    }
    cout << ans << endl;
    return 0;
}