#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int counter = 0;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    counter++;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;

    ll p = 1, q = 1;
    while (true) {
        counter = 0;
        gcd(p, q);
        if (counter == K) {
            break;
        }
        ll t = q;
        q = p;
        p += t;
    }
    cout << p << " " << q << endl;

    return 0;
}