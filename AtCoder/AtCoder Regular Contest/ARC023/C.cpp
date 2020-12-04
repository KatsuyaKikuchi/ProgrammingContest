#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll modpow(ll n, ll r) {
    ll ret = 1;
    ll p = n % MOD;
    while (r > 0) {
        if ((r & 1) == 1)
            ret = (ret * p) % MOD;
        p = (p * p) % MOD;
        r /= 2;
    }
    return ret % MOD;
}

ll cmb(ll l, ll r, ll m) {
    ll n = r - l + m;
    ll ret = 1;
    REP(i, m) {
        ret = ret * (n - i) % MOD;
    }
    ll inv = 1;
    REP(i, m) {
        inv = inv * (i + 1LL) % MOD;
    }

    return ret * modpow(inv, MOD - 2) % MOD;
}

ll A[2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll left = -1;
    ll ans = 1;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        if (A[i] < 0)
            continue;
        ll t = i - 1 - left;
        ans = ans * cmb(A[left], A[i], t) % MOD;
        left = i;
    }
    cout << ans % MOD << endl;
    return 0;
}