#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
pll T[200005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll s = 0, x = 0;
    ll si = 0;
    ll ans = 0;
    T[0] = pll(0, 0);
    REP(i, N) {
        s += A[i];
        x ^= A[i];
        T[i + 1] = pll(s, x);
        while (s - T[si].first != (x ^ T[si].second))
            si++;
        ans += i + 1 - si;
    }
    cout << ans << endl;
    return 0;
}