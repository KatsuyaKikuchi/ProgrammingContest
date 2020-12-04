#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

ll A[100005];
ll B[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N + 1) {
        cin >> A[i];
    }
    memset(B, 0, sizeof(B));
    for (ll i = N - 1; i >= 0; --i) {
        B[i] += B[i + 1];
        B[i] += A[i + 1];
    }
    ll p = 1;
    ll ans = 1;
    REP(i, N + 1) {
        p -= A[i];
        if (p < 0) {
            cout << -1 << endl;
            return 0;
        }
        p *= 2LL;
        p = std::min(p, B[i]);
        ans += p;
    }
    cout << ans << endl;
    return 0;
}