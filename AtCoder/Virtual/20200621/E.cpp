#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll modpow(ll n, ll r, ll mod) {
    ll ret = 1;
    ll p = n % mod;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % mod;
        r /= 2;
        p = (p * p) % mod;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, P;
    cin >> N >> P;
    string S;
    cin >> S;
    ll ans = 0;
    if (P == 2 || P == 5) {
        REP(i, N) {
            ll n = S[i] - '0';
            if (n % P == 0)
                ans += i + 1;
        }
    }
    else {
        map<ll, ll> M;
        M[0]++;
        ll p = modpow(10LL, P - 2, P);
        ll s = 0;
        REP(i, N) {
            s = (s * 10LL + S[i] - '0') % P;
            ll q = modpow(p, i + 1, P);
            ll n = s * q % P;
            ans += M[n];
            M[n]++;
        }
    }

    cout << ans << endl;
    return 0;
}