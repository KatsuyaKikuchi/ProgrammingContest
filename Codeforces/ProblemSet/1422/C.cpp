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
        p = p * p % MOD;
        r /= 2;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.length();

    ll ans = 0;
    ll p0 = 1, p1 = 0;
    REP(i, N) {
        ll index = N - i - 1;
        ll t = S[index] - '0';
        {
            ll r = ((index + 1) * index / 2) % MOD;
            ans += (t * r % MOD) * p0 % MOD;
            p0 = p0 * 10LL % MOD;
        }
        {
            ans += (t * p1) % MOD;
            p1 = (p1 + modpow(10LL, i) * (i + 1)) % MOD;
        }
        //cout << ans << endl;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}