#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
ll dp[200005];
ll dp2[200005][2];
ll P[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    REP(i, N + 1) {
        dp[i] = -INF;
        dp2[i][0] = dp2[i][1] = -INF;
    }

    ll ans = -INF;
    dp[0] = A[0];
    memset(P, 0, sizeof(P));
    if (N % 2 == 0) {
        dp[1] = A[0];
        dp[2] = A[1];
        for (ll i = 2; i < N ; ++i) {
            if (i % 2 == 0)
                dp[i + 1] = dp[i - 1] + A[i];
            else
                dp[i + 1] = std::max(dp[i - 1], dp[i - 2]) + A[i];
        }
        ans = std::max({ans, dp[N], dp[N - 1]});
    }
    else {
        dp[1] = A[0];
        dp[2] = A[1];
        for (ll i = 2; i < N - 1; ++i) {
            if (i % 2 == 0)
                dp[i + 1] = dp[i - 1] + A[i];
            else
                dp[i + 1] = std::max(dp[i - 1], dp[i - 2]) + A[i];
        }
        ans = std::max({ans, dp[N - 1], dp[N - 2]});

#if false
        REP(i, N) {
            cout << dp[i + 1] << endl;
        }
        cout << endl;
#endif

        dp2[0][0] = 0;
        dp2[0][1] = 0;
        dp2[1][0] = 0;
        dp2[1][1] = A[0];
        dp2[2][0] = A[1];
        dp2[3][0] = A[2];
        dp2[3][1] = A[0] + A[2];
        for (ll i = 3; i < N; ++i) {
            if (i % 2 == 1) {
                dp2[i + 1][0] = std::max(dp2[i - 1][0], dp2[i - 2][1]) + A[i];
            }
            else {
                dp2[i + 1][0] = std::max({dp2[i - 1][0], dp2[i - 2][0], dp2[i - 3][1]}) + A[i];
                dp2[i + 1][1] = dp2[i - 1][1] + A[i];
            }
        }

        ans = std::max({ans, dp2[N][0], dp2[N - 1][0], dp2[N - 2][1]});
        // ans = std::max(ans, s);
    }

    cout << ans << endl;

    return 0;
}