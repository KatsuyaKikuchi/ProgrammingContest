#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll D[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X;
    cin >> N >> X;
    REP(i, N) {
        cin >> D[i];
    }
    ll ans = 0;
    REP(i, N) {
        if (D[i] >= X) {
            ll t = D[i] * (D[i] + 1) / 2 - (D[i] - X) * (D[i] - X + 1) / 2;
            ans = std::max(ans, t);
        }
    }
    ll s = 0;
    ll sum = 0;
    ll mx = 0;
    REP(i, 2 * N) {
        sum += D[i % N];
        mx += D[i % N] * (D[i % N] + 1) / 2;
        if (sum >= X) {
            while (sum >= X) {
                sum -= D[s];
                mx -= D[s] * (D[s] + 1) / 2;
                s = (s + 1) % N;
            }
            ll d = X - sum;
            ll t = D[(N + s - 1) % N];
            ans = std::max(ans, mx + t * (t + 1) / 2 - (t - d) * (t - d + 1) / 2);
        }
        ans = std::max(ans, mx);
    }
    cout << ans << endl;
    return 0;
}