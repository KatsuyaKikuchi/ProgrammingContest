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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, V, B, W, T;
    cin >> A >> V >> B >> W >> T;
    if (V <= W) {
        cout << "NO" << endl;
        return 0;
    }
    ll D = abs(B - A);
    if (T * (V - W) >= D)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}