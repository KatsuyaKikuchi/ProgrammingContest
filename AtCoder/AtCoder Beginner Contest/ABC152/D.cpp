#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[10][10];

ll front(ll n) {
    ll p = n % 10;
    while (n > 0) {
        p = n % 10;
        n /= 10;
    }
    return p;
}

ll back(ll n) {
    return n % 10;
}

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    memset(A, 0, sizeof(A));
    for (ll n = 1; n <= N; ++n) {
        ll f = front(n);
        ll b = back(n);
        A[f][b]++;
    }
    for (ll n = 1; n <= N; ++n) {
        ll f = front(n);
        ll b = back(n);
        ans += A[b][f];
    }
    cout << ans << endl;
    return 0;
}