#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string X;

ll calc(ll m) {
    ll n = 0;

    ll x = 1;
    for (ll i = X.length() - 1; i >= 0; --i) {
        ll t = n + (X[i] - '0') * x;
        if (t < n)
            return -1;
        n = t;
        x *= m;
    }
    return n;
}

int main() {
    ll N;
    cin >> N;
    cin >> X;
    for (ll m = 10; m >= 2; --m) {
        ll n = calc(m);
        if (n == N) {
            cout << m << endl;
            break;
        }
    }
    return 0;
}