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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, Q;
    cin >> N >> Q;
    atcoder::dsu uf(N + 5);
    REP(_, Q) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            uf.merge(c, b);
        }
        else {
            cout << (ll) uf.same(b, c) << endl;
        }
    }
    return 0;
}