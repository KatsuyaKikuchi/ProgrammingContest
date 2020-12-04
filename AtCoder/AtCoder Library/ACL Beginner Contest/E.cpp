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

ll modpow(ll n, ll r) {
    ll ret = 1;
    ll p = n;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % MOD;
        p = (p * p) % MOD;
        r /= 2;
    }
    return ret;
}

ll P[200005];

ll sum(ll a, ll n) {
    ll ret = a * P[n] % MOD;
    return ret;
}

pll op(pll a, pll b) {
    ll p = (a.first * modpow(10LL, b.second) % MOD + b.first) % MOD;

    return pll(p, a.second + b.second);
}

pll e() { return pll(0, 0); }

pll mapping(ll a, pll b) {
    if (a == 0) {
        return b;
    }
    return pll(sum(a, b.second), b.second);
}

ll comp(ll a, ll b) {
    if (a == 0)
        return b;
    return a;
}

ll id() { return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, Q;
    cin >> N >> Q;
    P[0] = 0;
    REP(i, N + 2) {
        P[i + 1] = (P[i] * 10LL + 1) % MOD;
    }
    vector<pll> A(N);
    REP(i, N) {
        A[i] = pll(1, 1);
    }
    atcoder::lazy_segtree<pll, op, e, ll, mapping, comp, id> seg(A);
    REP(_, Q) {
        ll L, R, D;
        cin >> L >> R >> D;
        seg.apply(L - 1, R, D);
        cout << seg.prod(0, N).first << endl;
    }

    return 0;
}