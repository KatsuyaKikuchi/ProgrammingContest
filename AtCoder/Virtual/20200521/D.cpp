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
    ll mn = 0, mx = 0;
    REP(i, K) {
        mn += i;
        mx += N - i;
    }
    for (ll n = K; n <= N + 1; ++n) {
        ans += mx - mn + 1;
        ans %= MOD;
        mx += N - n;
        mn += n;
    }

    cout << ans << endl;
    return 0;
}