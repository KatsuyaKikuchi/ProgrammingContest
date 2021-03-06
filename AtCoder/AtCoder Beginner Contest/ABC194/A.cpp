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
    ll A, B;
    cin >> A >> B;
    if (A + B >= 15 && B >= 8) {
        cout << 1 << endl;
    }
    else if (A + B >= 10 && B >= 3) {
        cout << 2 << endl;
    }
    else if (A + B >= 3) {
        cout << 3 << endl;
    }
    else {
        cout << 4 << endl;
    }
    return 0;
}