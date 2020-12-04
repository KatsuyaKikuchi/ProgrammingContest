#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[305];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll xr = 0;
    FOR(i, N, 2) {
        xr ^= A[i];
    }

#if true
    std::cout << std::bitset<45>(A[0]) << endl;
    std::cout << std::bitset<45>(A[1]) << endl;
    std::cout << std::bitset<45>(xr) << endl;
#endif

    ll ans = A[0];
    while (true) {
        ll t = A[0] ^A[1] ^xr;
        ll p = 0;
        REP(i, 64) {
            if ((t >> i) & 1)
                p = i;
        }
        ll x = 1LL << p;
        if (x > A[0] && x < A[1]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << A[0] - ans << endl;
    return 0;
}