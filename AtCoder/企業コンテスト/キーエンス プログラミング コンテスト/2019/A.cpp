#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool U[10];

int main() {
    REP(i, 4) {
        ll a;
        cin >> a;
        U[a] = true;
    }

    if (U[1] && U[9] && U[7] && U[4])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}