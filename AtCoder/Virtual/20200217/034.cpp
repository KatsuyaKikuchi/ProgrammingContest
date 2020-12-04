#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll D[105];

int main() {
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    REP(i, N) {
        cin >> D[i];
    }
    sort(D, D + N, [](ll a, ll b) { return a > b; });
    ll ans = C / A;
    ll c = C, d = A;
    REP(i, N) {
        c += D[i];
        d += B;
        ans = std::max(ans, c / d);;
    }
    cout << ans << endl;
    return 0;
}