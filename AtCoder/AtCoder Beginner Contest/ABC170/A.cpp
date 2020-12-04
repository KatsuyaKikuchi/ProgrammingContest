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
    ll X[5];
    REP(i, 5) {
        cin >> X[i];
    }
    REP(i, 5) {
        if (X[i] == 0) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}