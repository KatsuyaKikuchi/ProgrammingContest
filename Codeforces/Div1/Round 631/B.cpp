#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[33];
ll dp[33][33];

ll solve(ll d, ll m) {

    memset(P, 0, sizeof(P));
    P[0] = 1;
    ll p = 1;
    REP(i, 31) {
        p *= 2LL;
        if (p * 2LL <= d)
            P[i + 1] = p;
        else
            P[i + 1] = std::max(0LL, d - p + 1);
    }

    ll ret = 0;
    for (ll n = 1; n <= 31; ++n) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        REP(i, 31) {
            REP(j, n + 1) {
                dp[i + 1][j] += dp[i][j];
                if (j > 0)
                    dp[i + 1][j] += (dp[i][j - 1] * P[i]);
                dp[i + 1][j] %= m;
            }
        }
        ret += dp[31][n];
        ret %= m;
    }
    return ret % m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll D, M;
        cin >> D >> M;
        cout << solve(D, M) << endl;
    }
    return 0;
}