#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
ll X[100005];

ll modpow(ll n) {
    ll s = 1, p = n;
    for (ll i = 0; (1LL << i) <= MOD - 2; ++i, p = (p * p) % MOD) {
        if (((MOD - 2) & (1 << i)) == 0)
            continue;
        s *= p;
        s %= MOD;
    }
    return s;
}

int main() {
    cin >> N;
    REP(i, N) {
        cin >> X[i];
    }
    ll P = 1;
    REP(i, N - 1) {
        P = (P * (i + 1)) % MOD;
    }

    ll p = 0;
    ll ans = 0;
    REP(i, N - 1) {
        ll x = X[i + 1] - X[i];
        p = (p + modpow(i + 1) * P) % MOD;
        ans = (ans + p * x) % MOD;
    }

    cout << ans << endl;
    return 0;
}