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
    ll Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;
    ll t = std::min({Q * 4, 2 * H, S});
    ll s = std::min(t * 2, D);
    ll ans = (N / 2) * s + (N % 2) * t;
    cout << ans << endl;
    return 0;
}