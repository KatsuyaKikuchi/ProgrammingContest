#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N, X, M;
    cin >> N >> X >> M;
    ll L = X, R = X;
    REP(i, M) {
        ll l, r;
        cin >> l >> r;
        if (r < L || R < l)
            continue;
        L = std::min(L, l);
        R = std::max(R, r);
    }
    return R - L + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}