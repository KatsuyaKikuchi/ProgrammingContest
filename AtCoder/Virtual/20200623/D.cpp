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
    ll p = n;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % MOD;
        p = (p * p) % MOD;
        r /= 2;
    }
    return ret;
}

ll cmb(ll n, ll r) {
    ll f = 1, inv = 1;
    REP(i, r) {
        f = (f * (n - i)) % MOD;
    }
    REP(i, r) {
        inv = (inv * (i + 1)) % MOD;
    }

    return f * modpow(inv, MOD - 2) % MOD;
}

ll A[2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = 1;
    REP(i, N) {
        if (A[i] < 0)
            continue;
        for (ll j = i - 1; j >= 0; --j) {
            if (A[j] < 0)
                continue;

            ll n = i - j - 1;
            ll m = A[i] - (A[j] - 1);
            //cout << n << " " << m << endl;
            ans = (ans * cmb(m + n - 1, n)) % MOD;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}