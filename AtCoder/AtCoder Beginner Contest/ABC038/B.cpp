#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll H0, W0, H1, W1;
    cin >> H0 >> W0 >> H1 >> W1;
    if (H0 == H1 || H0 == W1 || W0 == H1 || W0 == W1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}