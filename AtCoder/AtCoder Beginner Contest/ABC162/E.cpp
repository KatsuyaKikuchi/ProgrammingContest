#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll modpow(ll n, ll p) {
    ll ret = 1;
    ll t = n;
    while (p > 0) {
        if ((p & 1) == 1) {
            ret = ret * t % MOD;
        }
        p /= 2LL;

        t = (t * t) % MOD;
    }
    return ret;
}

ll P[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    memset(P, 0, sizeof(P));

    ll ans = 0;
    for (ll n = K; n >= 1; --n) {
        ll s = 0;
        ll m = 0;
        for (ll j = n; j <= K; j += n) {
            m++;
            s += P[j];
        }
        s %= MOD;

        ll p = modpow(m, N);
        P[n] = (MOD + p - s) % MOD;

        ans = (n * P[n] + ans) % MOD;

        //cout << n << " " << p << endl;
    }
    cout << ans << endl;


    return 0;
}