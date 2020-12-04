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
    ll W, a, b;
    cin >> W >> a >> b;
    ll ans = INF;
    if (a + W < b)
        ans = b - (a + W);
    else
        ans = a - (b + W);

    cout << std::max(0LL, ans) << endl;
    return 0;
}