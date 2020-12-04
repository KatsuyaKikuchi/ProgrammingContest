#include <bits/stdc++.h>
#include "atcoder/all"

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[300005];

ll op(ll a, ll b) { return std::max(a, b); };

ll e() { return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> B(300005, 0);
    atcoder::segtree<ll, op, e> seg(B);

    ll ans = 0;
    for (ll i = N - 1; i >= 0; --i) {
        ll mn = std::max(0LL, A[i] - K);
        ll mx = std::min(300002LL, A[i] + K) + 1;
        ll p = seg.prod(mn, mx) + 1;
        ans = std::max(ans, p);
        seg.set(A[i], p);
    }
    cout << ans << endl;
    return 0;
}