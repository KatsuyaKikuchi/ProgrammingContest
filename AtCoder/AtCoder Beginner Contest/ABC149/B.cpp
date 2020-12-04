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
    ll A, B, K;
    cin >> A >> B >> K;
    ll a = std::min(A, K);
    cout << A - a << " " << std::max(0LL, B - (K - a)) << endl;

   // cout << std::max(A - K, 0LL) << " " << std::max(B - K, 0LL) << endl;
    return 0;
}