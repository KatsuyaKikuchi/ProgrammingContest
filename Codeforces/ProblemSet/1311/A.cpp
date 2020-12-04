#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(ll a, ll b) {
    if (a == b)
        return 0;
    if (a > b) {
        if ((a - b) % 2 == 0)
            return 1;
        return 2;
    }

    if ((b - a) % 2 == 1)
        return 1;
    return 2;
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}