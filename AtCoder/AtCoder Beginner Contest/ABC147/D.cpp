#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[300005];
ll P[100];

int main() {
    ll N;
    cin >> N;
    memset(P, 0, sizeof(P));
    REP(i, N) {
        cin >> A[i];
        REP(j, 61) {
            if (((A[i] >> j) & 1) == 1)
                P[j]++;
        }
    }

    ll ans = 0;
    ll p = 1;
    REP(i, 61) {
        ans += (((p * P[i]) % MOD) * (N - P[i])) % MOD;
        p = (p * 2LL) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}