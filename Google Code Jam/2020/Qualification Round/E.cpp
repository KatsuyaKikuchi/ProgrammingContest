#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve(ll N, ll K) {
    if (N > 5) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }


}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(q, Q) {
        ll N, K;
        cin >> N >> K;

        cout << "Case #" << q + 1 << ": ";
        solve(N, K);
    }
    return 0;
}