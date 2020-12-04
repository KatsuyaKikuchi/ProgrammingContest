#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(ll N, ll G, ll B) {
    ll M = (N + 1) / 2;

    ll m = (M + G - 1) / G;
    ll ret = (m - 1) * B;
    ret += std::max(N - ret, M);
    return ret;
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N, G, B;
        cin >> N >> G >> B;
        cout << solve(N, G, B) << endl;
    }
    return 0;
}