#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll P;
    cin >> P;
    ll a = 1, b = 1;
    ll idx = 3;
    if (P == 1) {
        cout << 1 << endl;
        return 0;
    }
    while (idx <= 1000000) {
        ll t = (a + b) % P;
        if (t == 0) {
            cout << idx << endl;
            return 0;
        }
        idx++;
        a = b;
        b = t;
    }
    cout << -1 << endl;
    return 0;
}