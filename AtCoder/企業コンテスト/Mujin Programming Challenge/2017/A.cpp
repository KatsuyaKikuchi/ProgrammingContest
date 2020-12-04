#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll X[100005];
ll P[100005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> X[i];
    }

    P[0] = P[1] = 1;
    for (ll i = 1; i <= N; ++i) {
        P[i + 1] = (P[i] * (i + 1)) % MOD;
    }

    ll ans = 1;
    ll s = X[0];
    ll n = 1;
    REP(i, N - 1) {
        s += X[i + 1] - X[i] - 1;
        n++;
        if (n > s) {
            ans = (ans * n) % MOD;
            s++;
            n--;
        }
    }
    ans = (ans * P[n]) % MOD;
    cout << ans << endl;
    return 0;
}