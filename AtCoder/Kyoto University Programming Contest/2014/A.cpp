#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll A[3], B[3];
    REP(i, 3) {
        cin >> A[i];
    }
    REP(i, 3) {
        cin >> B[i];
    }
    sort(A, A + 3);
    sort(B, B + 3);
    ll ans = 0;
    REP(i, 3) {
        ans += abs(A[i] - B[i]);
    }
    cout << ans << endl;
    return 0;
}