#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

//! 0~nの排他的論理和
ll calc(ll n) {
    ll m = n;
    ll b = 0;
    while (n > 0) {
        ll p = 1LL;
        while (p * 2LL <= n) {
            p <<= 1LL;
        }
        n = n & (~p);
        if (n % 2 == 0)
            b |= p;
    }
    if ((m - 2) > 0 && (m - 2) % 4 == 0)
        b++;
    if ((m + 1) % 4 == 0)
        b--;
    return b;
}

int main() {
    ll A, B;
    cin >> A >> B;
    if (A == 0)
        cout << calc(B) << endl;
    else
        cout << (calc(B) ^ calc(A - 1)) << endl;
    return 0;
}