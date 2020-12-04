#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll D[505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll sum = 0;
    ll mx = 0;
    REP(i, N) {
        cin >> D[i];
        sum += D[i];
        mx = std::max(mx, D[i]);
    }

    cout << sum << endl;
    cout << std::max(0LL, mx - (sum - mx)) << endl;

    return 0;
}