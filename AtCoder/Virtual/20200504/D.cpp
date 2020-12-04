#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = -INF;
    REP(i, N) {
        pll score = pll(-INF, -INF);
        REP(j, N) {
            if (i == j) {
                continue;
            }

            vector<ll> v;
            for (ll n = std::min(i, j); n <= std::max(i, j); ++n) {
                v.push_back(A[n]);
            }

            ll t = 0, a = 0;
            REP(n, v.size()) {
                if (n % 2 == 0)
                    t += v[n];
                else
                    a += v[n];
            }
            if (a > score.second) {
                score = pll(t, a);
            }
        }
        ans = std::max(ans, score.first);
    }
    cout << ans << endl;
    return 0;
}