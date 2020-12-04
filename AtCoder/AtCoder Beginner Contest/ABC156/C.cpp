#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll X[105];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> X[i];
    }
    ll ans = INF;
    REP(i, 101) {
        ll m = 0;
        REP(j, N) {
            m += pow(X[j] - i, 2);
        }
        ans = std::min(ans, m);
    }
    cout << ans << endl;
    return 0;
}