#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

ll solve() {
    ll N, D;
    ll X[3];
    cin >> N >> X[0] >> X[1] >> X[2] >> D;
    ll P[3] = {2, 3, 5};
    ll ret = INF;
    stack<pll> s;
    s.push(pll(N, 0));
    std::map<ll, ll> memo;
    while (!s.empty()) {
        pll t = s.top();
        s.pop();
        if (ret <= t.second || t.first == 0)
            continue;
        if ((ret - t.second) / t.first > D)
            ret = D * t.first + t.second;
        REP(i, 3) {

        }
    }
    return ret;
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