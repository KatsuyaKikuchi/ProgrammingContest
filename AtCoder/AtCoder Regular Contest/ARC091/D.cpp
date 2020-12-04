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
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    FOR(b, N + 1, 1) {
        if (b <= K)
            continue;
        for (ll i = b; i <= N + b; i += b) {
            ll l = std::max(1LL, K + i - b);
            if (l > N)
                break;
            ll r = std::min(N, b - 1 + i - b);
            ans += r - l + 1;
        }
    }

    cout << ans << endl;
    return 0;
}