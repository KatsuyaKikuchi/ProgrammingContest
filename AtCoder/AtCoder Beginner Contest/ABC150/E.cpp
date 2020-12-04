#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[200005];
//! 長さNであるもので、
ll P[200005];
ll Q[200005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> C[i];
    }

    P[0] = 1;
    REP(i, N) {
        P[i + 1] = (P[i] * 4LL) % MOD;
    }
    Q[0] = 0;
    ll p = 1;
    REP(i, N) {
        Q[i + 1] = (p * 2LL * (i + 1)) % MOD;
        Q[i + 1] = (Q[i + 1] * p) % MOD;
        p = (p * 2) % MOD;
    }

    sort(C, C + N, [](ll a, ll b) { return a > b; });

    ll ans = 0;
    ll s = 0;
    REP(i, N) {
        ans = (ans + (P[N - 1] * C[i] * 2LL) % MOD) % MOD;
        ll t = (2LL * Q[i] * P[N - 1 - i]) % MOD;
        ans = (ans + C[i] * t) % MOD;
    }

    cout << ans << endl;
    return 0;
}