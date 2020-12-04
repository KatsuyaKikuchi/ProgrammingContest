#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;

    ll N = 2000005;
    vector<ll> P(N + 1, 0), Q(N + 1, 0);
    P[1] = P[2] = 0;
    Q[1] = Q[2] = 0;
    FOR(i, N, 2) {
        P[i + 1] = (2LL * Q[i - 1] + Q[i] + 1LL) % MOD;
        Q[i + 1] = (2LL * std::max(P[i - 1], Q[i - 1]) + std::max(P[i], Q[i])) % MOD;
    }
    REP(_, T) {
        ll M;
        cin >> M;
        cout << ((4LL * std::max(Q[M], P[M])) % MOD) << endl;
    }
    return 0;
}