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
    ll K, A, B;
    cin >> K >> A >> B;
    ll m = A - B;
    ll s = std::max(K - A, 0LL);
    if (s > 0) {
        if (m <= 0)
            cout << -1 << endl;
        else
            cout << 1 + 2 * ((s + m - 1) / m);
    }
    else
        cout << 1 << endl;

    return 0;
}