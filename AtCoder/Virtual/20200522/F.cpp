#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[100005];

ll modpow(ll n, ll r) {
    ll p = n;
    ll ret = 1;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % MOD;
        p = (p * p) % MOD;
        r >>= 1;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for (ll k = K; k > 0; --k) {
        ll n = K / k;
        ll p = modpow(n, N);
        for (ll j = k; j <= K; j += k) {
            p = (MOD + p - P[j]) % MOD;
        }
        ans = (ans + k * p) % MOD;
        P[k] = p;
    }

    cout << ans << endl;
    return 0;
}