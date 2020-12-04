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
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    for (ll i = K; i <= N + 1; ++i) {
        ll b = i * (i - 1) / 2;
        ll n = (N - i);
        ll t = N * (N + 1) / 2 - n * (n + 1) / 2;

        ans = (ans + t - b + 1) % MOD;
    }
    cout << ans << endl;
    return 0;
}