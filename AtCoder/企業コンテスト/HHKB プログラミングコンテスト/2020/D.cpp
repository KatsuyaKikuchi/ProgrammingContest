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

ll sum(ll A, ll N, ll D) {
    ll ret = 2LL * A % MOD + ((MOD - 1 + N) % MOD) * D % MOD;
    ret %= MOD;
    ret *= modpow(2LL, MOD - 2);
    return ret % MOD;
}

ll solve() {
    ll N, A, B;
    cin >> N >> A >> B;
    if (A > B)
        swap(A, B);

    ll ret = (((N - A + 1) * (N - A + 1) % MOD) * ((N - B + 1) * (N - B + 1) % MOD)) % MOD;
    ll div = (N - B + 1);
    ll num = div / 2;
    ll p = std::min(num, A);
    {
        ll s = sum(B, p, B);
        ll t = 4LL * sum(s, p, ((p - 1) * B % MOD)) % MOD;
        ret = (ret + MOD - t) % MOD;
    }
    ll r = N - B + 1 - 2 * p;
    {
        ll s = (B + A - 1) * r % MOD;
        ll t = 4LL * sum(s, p, ((p - 1) * B % MOD)) % MOD;
        ret = (ret + MOD - t) % MOD;
    }
    {
        ll s = (B + A - 1) * (B + A - 1) % MOD;
        ll t = (s * r % MOD) * r % MOD;
        ret = (ret + MOD - t) % MOD;
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}