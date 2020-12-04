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
    ll N, A, B, C, D, E;
    cin >> N >> A >> B >> C >> D >> E;
    ll m = std::min({A, B, C, D, E});

    ll ans = 5 + ((N + m - 1) / m - 1);
    cout << ans << endl;
    return 0;
}