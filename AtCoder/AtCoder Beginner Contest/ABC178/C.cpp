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
        if (r & 1) {
            ret = (ret * p) % MOD;
        }
        p = (p * p) % MOD;
        r /= 2;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = modpow(10, N);
    ll t = (modpow(9, N) * 2LL - modpow(8, N) + MOD) % MOD;
    cout << (MOD + ans - t) % MOD << endl;

    return 0;
}