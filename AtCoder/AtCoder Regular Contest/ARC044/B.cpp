#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
ll M[100005];
ll P[100005];

ll modpow(ll n, ll p) {
    ll m = 1LL;
    REP(i, 40) {
        if (((p >> i) & 1) == 1)
            m = (m * n) % MOD;
        n = (n * n) % MOD;
    }
    return m;
}

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    ll max = 0;
    memset(M, 0, sizeof(M));
    REP(i, N) {
        M[A[i]]++;
        max = std::max(A[i], max);
    }
    if (A[0] != 0 || M[0] > 1) {
        cout << 0 << endl;
        return 0;
    }

    P[0] = 1;
    REP(i, N) {
        P[i + 1] = (P[i] * 2LL) % MOD;
    }
    ll ans = 1;
    REP(i, max) {
        ans = (ans * modpow(P[M[i]] - 1, M[i + 1])) % MOD;
        ans = (ans * modpow(2, M[i + 1] * (M[i + 1] - 1) / 2)) % MOD;
    }
    cout << ans << endl;
    return 0;
}