#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 3) {
        cin >> A[i];
    }
    ll ans = 0;
    while (A[0] != A[1] || A[1] != A[2] || A[2] != A[0]) {
        ans++;
        ll mx = std::max({A[0], A[1], A[2]});
        ll n = 0;
        REP(i, 3) {
            if (A[i] < mx)
                n++;
        }
        REP(i, 3) {
            if (n == 2 && A[i] < mx) {
                A[i]++;
            }
            else if (n == 1 && A[i] < mx) {
                A[i] += 2;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}