#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll t;
    pll g;
};

Data D[100005];
ll dp[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll R, N;
    cin >> R >> N;
    REP(i, N) {
        cin >> D[i + 1].t >> D[i + 1].g.first >> D[i + 1].g.second;
    }
    D[0].g = pll(1, 1);
    D[0].t = 0;

    memset(dp, 0, sizeof(dp));
    REP(i, N) {
        dp[i + 1] = -INF;
    }
    REP(i, N) {
        REP(j, i + 1) {
            ll d = abs(D[i + 1].g.first - D[j].g.first) + abs(D[i + 1].g.second - D[j].g.second);
            if (D[i + 1].t - D[j].t >= d)
                dp[i + 1] = std::max(dp[i + 1], dp[j] + 1);
        }
    }

    ll ans = 0;
    REP(i, N + 1) {
        ans = std::max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}