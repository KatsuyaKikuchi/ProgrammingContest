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

ll op(ll a, ll b) {
    return std::max(a, b);
}

ll e() {
    return -1;
}

ll target;

bool f(ll v) {
    return v < target;
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

    auto seg = atcoder::segtree<ll, op, e>(A);

    REP(_, Q) {
        ll t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            seg.set(a - 1, b);
        }
        else if (t == 2) {
            ll m = seg.prod(a - 1, b);
            cout << m << endl;
        }
        else {
            target = b;
            ll m = seg.max_right<f>(a - 1) + 1;
            cout << m << endl;
        }
    }
    return 0;
}