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
    ll N, K;
    cin >> N >> K;
    if (K <= N) {
        cout << K * K * K << endl;
    }
    else if (K <= 2 * N) {
        ll ans = K * K * K - (K - N) * (K - N) * (K - N) * 3;
        cout << ans << endl;
    }
    else {
        ll t = std::max(3 * N - K, 0LL);
        cout << N * N * N * 6LL - t * t * t << endl;
    }
    return 0;
}