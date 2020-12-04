#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    memset(S, 0, sizeof(S));
    for (ll n = 2; n <= 2 * N; ++n) {
        ll mn = std::max(1LL, n - N);
        ll mx = std::min(N, n - 1);
        S[n] = mx - mn + 1;
    }

    ll ans = 0;
    for (ll n = 2; n <= 2 * N; n++) {
        ll k = n - K;
        if (2 <= k && k <= 2 * N)
            ans += S[k] * S[n];
    }
    cout << ans << endl;

    return 0;
}