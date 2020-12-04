#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[2005];
ll dp[2005][2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, H, L, R;
    cin >> N >> H >> L >> R;
    REP(i, N) {
        cin >> A[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    REP(i, N) {
        REP(j, H) {
            if (dp[i][j] < 0)
                continue;

            {
                ll h = (j + A[i]) % H;
                ll s = dp[i][j];
                if (L <= h && h <= R)
                    s++;
                dp[i + 1][h] = std::max(dp[i + 1][h], s);
            }
            {
                ll h = (j + A[i] - 1) % H;
                ll s = dp[i][j];
                if (L <= h && h <= R)
                    s++;
                dp[i + 1][h] = std::max(dp[i + 1][h], s);
            }
        }
    }

    ll ans = 0;
    REP(i, H) {
        ans = std::max(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}