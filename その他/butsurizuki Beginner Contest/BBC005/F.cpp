#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, P;
    cin >> N >> P;

    ll r = N;
    ll g = gcd(N, P);
    N /= g;
    P /= g;

    ll n = modpow(N, r);
    ll p = modpow(P, r);

    ll ans = n * modpow(p, MOD - 2) % MOD;
    cout << ans << endl;
    return 0;
}