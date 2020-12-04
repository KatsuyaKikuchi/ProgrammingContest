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
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    pll ans(100 * A, 0);
    REP(a, 31) {
        if (100 * A * a > F)
            break;
        REP(b, 31) {
            ll n = 100 * A * a + 100 * B * b;
            if (n > F)
                break;
            REP(c, 301) {
                if (c * C + n > F || c * C > (n / 100) * E)
                    break;
                REP(d, 301) {
                    ll m = c * C + d * D;
                    if (n + m > F || m > (n / 100) * E)
                        break;

                    if (ans.second * (n + m) <= m * ans.first) {
                        ans = pll(n + m, m);
                    }
                }
            }
        }
    }
    cout << ans.first << " " << ans.second << endl;
    return 0;
}