#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[10005];
pll A[505];
ll S[10005];

ll dp[505][10005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll M, N;
    cin >> M >> N;
    REP(i, M) {
        cin >> P[i];
    }
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    sort(P, P + M, greater<ll>());
    memset(S, 0, sizeof(S));
    REP(i, M) {
        S[i + 1] = S[i] + P[i];
    }
    memset(dp, 0, sizeof(dp));
    REP(i, N) {
        REP(j, M + 1) {
            dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);
            ll nxt = std::min(M, j + A[i].first);
            ll s = S[nxt] - S[j];
            dp[i + 1][nxt] = std::max({dp[i][nxt], dp[i + 1][nxt], dp[i][j] + s - A[i].second});
        }
    }

    ll ans = 0;
    REP(i, M + 1) {
        ans = std::max(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}