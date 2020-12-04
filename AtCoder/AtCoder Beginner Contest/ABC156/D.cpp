#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll modpow(ll n, ll k) {
    ll s = 1, p = n;
    for (ll i = 0; (1LL << i) <= k; ++i, p = (p * p) % MOD) {
        if (((k) & (1 << i)) == 0)
            continue;
        s *= p;
        s %= MOD;
    }
    return s;
}

ll combination(ll n, ll r) {
    ll p = 1;
    REP(i, r) {
        p = (p * (n - i)) % MOD;
    }
    ll ip = 1;
    REP(i, r) {
        ip = (ip * (i + 1)) % MOD;
    }
    ip = modpow(ip, MOD - 2);
    return (p * ip) % MOD;
}

int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    ll p = modpow(2, N) - 1;
    ll ca = combination(N, A);
    ll cb = combination(N, B);

    p = (p + MOD - ca) % MOD;
    p = (p + MOD - cb) % MOD;
    cout << p << endl;

    return 0;
}