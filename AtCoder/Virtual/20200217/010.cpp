#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[6] = {500, 100, 50, 10, 5, 1};

ll dfs(ll idx, ll m, ll n) {
    if (m == 0) {
        return n;
    }
    if (idx >= 6) {
        return INF;
    }

    ll min = INF;
    for (ll i = 0; i * C[idx] <= m; ++i) {
        ll c = i * C[idx];
        min = std::min(min, dfs(idx + 1, m - c, n + i));
    }
    return min;
}

int main() {
    ll N;
    cin >> N;
    ll M = 1000 - N;
    ll ans = dfs(0, M, 0);
    cout << ans << endl;
    return 0;
}