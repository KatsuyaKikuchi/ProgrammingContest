#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N;
    cin >> N;
    if (N == 1) {
        cout << 9 << endl;
    }
    else if (N == 2) {
        cout << 98 << endl;
    }
    else {
        cout << 98;
        ll n = 9;
        REP(i, N - 2) {
            cout << n;
            n = (n + 1) % 10;
        }
        cout << endl;
    }

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