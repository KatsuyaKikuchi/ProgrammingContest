#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

//! m^p %MOD
ll modpow(ll m, ll p) {
    ll t = m % MOD;
    ll ret = 1;
    REP(i, 60) {
        if ((p >> i) & 1) {
            ret = ret * t % MOD;
        }
        t = t * t % MOD;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M, L, R;
    cin >> N >> M >> L >> R;
    if (L == R) {
        cout << 1 << endl;
        return 0;
    }
    if ((N * M) % 2 == 1) {
        cout << modpow(R - L + 1, N * M) << endl;
        return 0;
    }

    ll even = R / 2 - (L - 1) / 2;
    ll odd = R - L + 1 - even;

    if (even == odd) {
        ll ans = modpow(2LL, N * M - 1) * modpow(odd, N * M) % MOD;
        cout << ans << endl;
        return 0;
    }

    ll t = modpow(odd + even, N * M) + 1LL;
    t = (t * modpow(2LL, MOD - 2)) % MOD;
    cout << t << endl;
    return 0;
}