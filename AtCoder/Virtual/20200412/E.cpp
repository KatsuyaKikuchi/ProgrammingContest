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
    pll ans(0, 100 * A);
    for (ll a = 0;; a++) {
        if (100 * a * A > F)
            break;
        for (ll b = 0;; b++) {
            ll s = 100LL * a * A + 100LL * b * B;
            if (s > F)
                break;
            for (ll c = 0;; c++) {
                if (s + C * c > F)
                    break;
                if (E * (a * A + b * B) < C * c)
                    break;
                for (ll d = 0;; d++) {
                    ll t = C * c + D * d;
                    if (s + t > F)
                        break;
                    if (E * (a * A + b * B) < t)
                        break;

                    if (ans.first * (s + t) < ans.second * t) {
                        ans = pll(t, s + t);
                    }
                }
            }
        }
    }

    cout << ans.second << " " << ans.first << endl;
    return 0;
}