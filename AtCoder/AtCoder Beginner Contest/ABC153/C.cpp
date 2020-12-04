#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H[200005];

int main() {
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> H[i];
    }
    sort(H, H + N);
    ll ans = 0;
    REP(i, N - K) {
        ans += H[i];
    }
    cout << ans << endl;
    return 0;
}