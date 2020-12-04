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
    ll A, B;
    cin >> A >> B;
    if (A > B)
        cout << A + std::max(A - 1, B) << endl;
    else
        cout << B + std::max(A, B - 1) << endl;
    return 0;
}