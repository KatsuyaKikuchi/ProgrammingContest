#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[10005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, S, T, W;
    cin >> N >> S >> T >> W;
    A[0] = W;
    REP(i, N - 1) {
        ll a;
        cin >> a;
        A[i + 1] = A[i] + a;
    }
    ll ans = 0;
    REP(i, N) {
        if (A[i] >= S && A[i] <= T)
            ans++;
    }
    cout << ans << endl;
    return 0;
}