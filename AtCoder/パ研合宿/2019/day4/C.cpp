#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll D[3];

int main() {
    REP(i, 3) {
        cin >> D[i].first >> D[i].second;
    }

    double ans = 0;
    FOR(n, D[0].second + 1, D[0].first) {
        double p = 1.0 / (double) (D[0].second - D[0].first + 1);

        p *= std::min(1.0, ((double) (std::max(0LL, D[1].second - n)) / (double) (D[1].second - D[1].first + 1)));
        p *= std::min(1.0, ((double) (std::max(0LL, D[2].second - n)) / (double) (D[2].second - D[2].first + 1)));

        ans += p;
    }

    cout << OF64 << ans << endl;
    return 0;
}