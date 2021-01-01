#include <bits/stdc++.h>
#include "atcoder/all"

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;

ll op(ll l, ll r) { return min(l, r); }

ll e() { return N; }

ll mapping(ll l, ll r) { return min(l, r); }

ll composition(ll l, ll r) { return min(l, r); }

ll id() { return N; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> N >> Q;

    atcoder::lazy_segtree<ll, op, e, ll, mapping, composition, id> col(N + 5);
    atcoder::lazy_segtree<ll, op, e, ll, mapping, composition, id> row(N + 5);
    ll ans = (N - 2) * (N - 2);
    REP(_, Q) {
        ll t, x;
        cin >> t >> x;
        if (t == 1) {
            ll n = col.get(x);
            //cout << n << endl;
            ans -= std::max(n - 2, 0LL);
            row.apply(0, n, x);
        }
        else {
            ll n = row.get(x);
            //cout << n << endl;
            ans -= std::max(n - 2, 0LL);
            col.apply(0, n, x);
        }
    }
    cout << ans << endl;
    return 0;
}