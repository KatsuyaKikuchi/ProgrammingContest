#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    if (X == Y && X >= Z) {
        cout << "YES" << endl;
        cout << X << " " << Z << " " << Z << endl;
        return;
    }
    if (Y == Z && Y >= X) {
        cout << "YES" << endl;
        cout << X << " " << X << " " << Y << endl;
        return;
    }
    if (Z == X && Z >= Y) {
        cout << "YES" << endl;
        cout << Y << " " << X << " " << Y << endl;
        return;
    }
    cout << "NO" << endl;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}