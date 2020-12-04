#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

ll calc(ll x, ll y, ll z) {
    return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}

ll solve(vector<ll> &x, vector<ll> &y, vector<ll> &z) {
    ll ret = 2LL * INF + 10LL;
    ll zi = 0;
    REP(i, y.size()) {
        ll xi = 0, ng = x.size();
        while (abs(ng - xi) > 1) {
            ll mid = (xi + ng) / 2;
            if (x[mid] <= y[i])
                xi = mid;
            else
                ng = mid;
        }
        while (zi < z.size() - 1 && z[zi] < y[i])
            zi++;
        if (z[zi] < y[i])
            break;

        ret = std::min(ret, calc(x[xi], y[i], z[zi]));
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll nr, ng, nb;
        cin >> nr >> ng >> nb;
        vector<ll> R(nr), G(ng), B(nb);
        REP(i, nr) {
            cin >> R[i];
        }
        REP(i, ng) {
            cin >> G[i];
        }
        REP(i, nb) {
            cin >> B[i];
        }
        sort(R.begin(), R.end());
        sort(G.begin(), G.end());
        sort(B.begin(), B.end());

        ll ans = std::min(
                {
                        solve(R, G, B),
                        solve(R, B, G),
                        solve(G, R, B),
                        solve(G, B, R),
                        solve(B, R, G),
                        solve(B, G, R)
                });
        cout << ans << endl;
    }
    return 0;
}