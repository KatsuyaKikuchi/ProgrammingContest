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

    map<ll, ll> map;
    map[0] = 0;
    ll n = 1;
    while (true) {
        ll m = pow(n, 5);
        ll t = map[m - X];
        ll tt = pow(t, 5);
        if (m - tt == X) {
            cout << n << " " << t << endl;
            break;
        }
        map[m] = n;
        map[-m] = -n;
        n++;
    }
    return 0;
}