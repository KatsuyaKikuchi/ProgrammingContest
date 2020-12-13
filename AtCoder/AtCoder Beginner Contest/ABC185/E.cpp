#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[10005];
ll B[10005];

ll dp[1005][1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }

    memset(dp, 0, sizeof(dp));
    REP(i, N + 2) {
        REP(j, M + 2) {
            dp[i][j] = INF;
        }
    }
    REP(i, N) {
        dp[i + 1][0] = i + 1;
    }
    REP(j, M) {
        dp[0][j + 1] = j + 1;
    }
    dp[0][0] = 0;
    REP(i, N) {
        REP(j, M) {
            dp[i + 1][j + 1] = std::min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
            if (A[i] == B[j])
                dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j]);
        }
    }

#if false
    REP(i, N) {
        REP(j, M) {
            cout << dp[i + 1][j + 1] << " ";
        }
        cout << endl;
    }
#endif
    ll ans = dp[N][M];
    REP(i, M) {
        //  ans = std::min(ans, dp[N][i]);
    }
    cout << ans << endl;

    return 0;
}