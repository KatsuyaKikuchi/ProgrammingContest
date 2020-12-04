#include <bits/stdc++.h>
#include "atcoder/all"

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

ll op(ll a, ll b) {
    return (a + b) % MOD;
}

ll e() {
    return 0;
}

ll mapping(pll x, ll a) {
    return (a * x.first + x.second) % MOD;
}

pll comp(pll a, pll b) {
    return pll((a.first * b.first) % MOD, (a.second * b.first + b.second) % MOD);
}

pll id() {
    return pll(1, 0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    auto seg = atcoder::lazy_segtree<ll, op, e, pll, mapping, comp, id>(A);
    REP(_, Q) {
        ll t;
        cin >> t;
        if (t == 0) {
            ll l, r, b, c;
            cin >> l >> r >> b >> c;
            seg.apply(l, r, pll(b, c));
        }
        else {
            ll l, r;
            cin >> l >> r;
            cout << seg.prod(l, r) << endl;
        }
    }
    return 0;
}