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
    ll X;
    cin >> X;
    REP(i, 100) {
        ll t = 400 + 200 * i;
        if (t <= X && X < t + 200) {
            cout << 8 - i << endl;
            break;
        }
    }
    return 0;
}