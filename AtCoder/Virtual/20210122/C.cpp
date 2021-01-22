#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T[2], A[2], B[2];
    cin >> T[0] >> T[1];
    cin >> A[0] >> A[1];
    cin >> B[0] >> B[1];
    if (A[0] > B[0]) {
        swap(A[0], B[0]);
        swap(A[1], B[1]);
    }
    //! A[0]<B[0]
    ll a = T[0] * A[0] + T[1] * A[1];
    ll b = T[0] * B[0] + T[1] * B[1];
    ll d = a - b;
    if (d == 0) {
        cout << "infinity" << endl;
        return 0;
    }
    if (d < 0) {
        cout << 0 << endl;
        return 0;
    }

    ll t = ((B[0] - A[0]) * T[0] + d - 1) / d;
    ll ans = t * 2 - 1;
    if (((B[0] - A[0]) * T[0]) % d == 0)
        ans++;
    cout << ans << endl;
    return 0;
}