#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll modpow(ll n, ll r, ll mod) {
    ll ret = 1;
    ll p = n % mod;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % mod;
        p = (p * p) % mod;
        r >>= 1LL;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    ll ans = modpow(10, N, M * M) / M;
    cout << ans << endl;

    return 0;
}