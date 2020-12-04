#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
ll C[200005];
ll I[200005];

ll modpow(ll n, ll r) {
    ll ret = 1;
    ll p = n;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % MOD;
        p = (p * p) % MOD;
        r /= 2;
    }
    return ret;
}

ll cmb(ll r) {
    return C[r] * modpow(I[r], MOD - 2) % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }

    I[0] = 1;
    C[0] = 1;
    REP(i, N) {
        I[i + 1] = I[i] * (i + 1) % MOD;
        C[i + 1] = C[i] * (K + i + 1) % MOD;
    }

    ll ans = 0;
    REP(i, N) {
        ll l = i + 1;
        ll r = N - i;
        ll c = cmb(l - 1) * cmb(r - 1) % MOD;
        ans += (A[i] * c) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}