#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 2019;
const ll INF = (ll) 1e15;

ll modpow(ll n, ll p, ll mod) {
    ll ret = 1;
    ll r = n;
    while (p > 0) {
        if ((p & 1) == 1) {
            ret = ret * r % mod;
        }
        r = r * r % mod;
        p >>= 1;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.length();
    ll sum = 0;
    ll ans = 0;
    map<ll, ll> m;
    m[0]++;
    REP(i, N) {
        ll p = modpow(10, N - i, MOD);
        sum = (sum * 10LL + S[i] - '0') % MOD;
        ll t = sum * p % MOD;
        ans += m[t];
        m[t]++;
    }
    cout << ans << endl;
    return 0;
}