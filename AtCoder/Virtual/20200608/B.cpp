#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
ll B[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    memset(B, 0, sizeof(B));
    ll mx = 0;
    REP(i, N) {
        cin >> A[i];
        B[A[i]]++;
        mx = std::max(mx, A[i]);
    }
    ll ans = 0;
    FOR(i, mx + 2, 1) {
        ans = std::max(ans, B[i - 1] + B[i] + B[i + 1]);
    }
    cout << ans << endl;
    return 0;
}