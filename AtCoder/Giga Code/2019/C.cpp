#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];

int main() {
    ll D;
    cin >> D;
    REP(i, D) {
        cin >> A[i];
    }

    ll s = 0;
    ll min = INF;
    REP(i, D) {
        ll b;
        cin >> b;
        s += A[i];
        if (s >= b)
            min = std::min(min, b);
    }

    if (min == INF)
        min = -1;
    cout << min << endl;

    return 0;
}