#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll modpow(ll n) {
    ll p = 1LL;
    ll t = 1LL;
    REP(i, 60) {
        t = t * 3LL % MOD;
        if ((n >> i) & 1)
            p = p * t % MOD;
    }
    return p;
}

ll solve(ll n) {
    if (n <= 3)
        return n;

    ll m = n / 3;
    if ((n - 4) % 3 == 0) {
        return modpow(m - 1) * 4LL % MOD;
    }
    return modpow(m) * std::max(1LL, (n - m * 3LL)) % MOD;
}

int main() {
    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll n;
        cin >> n;
        cout << solve(n) << " ";
    }
    cout << endl;
    return 0;
}