#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll calc(ll x) {
    ll n = 1;
    ll m = x;
    ll ret = 0;
    while (m > 0) {
        ret += n * (m % 10);
        m /= 10;
        n *= x;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll x = 11;
    while (true) {
        ll n = calc(x);
        if (n == N) {
            cout << x << endl;
            return 0;
        }
        if (n > N)
            break;
        x++;
    }
    cout << -1 << endl;
    return 0;
}