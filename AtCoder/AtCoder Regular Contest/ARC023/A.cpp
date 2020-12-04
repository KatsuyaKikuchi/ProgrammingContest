#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;


ll get(ll y, ll m, ll d) {
    return 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 429;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll y, m, d;
    cin >> y >> m >> d;
    if (m <= 2) {
        m += 12;
        y--;
    }
    cout << get(2014, 5, 17) - get(y, m, d) << endl;
    return 0;
}