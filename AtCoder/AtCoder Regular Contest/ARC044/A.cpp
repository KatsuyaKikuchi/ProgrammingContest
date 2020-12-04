#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool check(ll n) {
    if (n % 2 == 0 || n % 5 == 0)
        return false;
    ll s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s % 3 != 0;
}

int main() {
    ll N;
    cin >> N;
    bool isPrime = true;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0)
            isPrime = false;
    }

    if ((check(N) || isPrime) && N != 1)
        cout << "Prime" << endl;
    else
        cout << "Not Prime" << endl;
    return 0;
}