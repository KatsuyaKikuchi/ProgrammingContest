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
    ll A;
    cin >> A;
    ll n = 10;
    while (n <= 10000) {
        ll p = 1;
        ll t = n;
        ll x = 0;

        while (t > 0) {
            x += (t % 10) * p;
            p *= n;
            t /= 10;
        }

        if (x == A) {
            cout << n << endl;
            return 0;
        }
        n++;
    }
    cout << -1 << endl;
    return 0;
}