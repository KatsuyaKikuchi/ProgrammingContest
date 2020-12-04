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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = INF;
    REP(i, std::max(X + 1, Y + 1)) {
        ans = std::min(ans, 2LL * i * C + std::max(0LL, X - i) * A + std::max(0LL, Y - i) * B);

    }
    cout << ans << endl;
    return 0;
}