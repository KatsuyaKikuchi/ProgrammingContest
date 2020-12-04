#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll sum(ll n) {
    ll s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

bool U[1000005];

int main() {
    ll N;
    cin >> N;

    memset(U, 0, sizeof(U));
    U[N] = true;
    ll ans = 1;
    for (ll i = N - 1; i > 0; --i) {
        ll s = sum(i);
        if (s + i <= N && U[s + i]) {
            U[i] = true;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}