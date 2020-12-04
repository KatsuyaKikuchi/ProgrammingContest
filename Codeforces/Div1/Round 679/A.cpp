#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[10];
ll B[100005];
ll dp[100005][10];
ll dp2[100005][10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 6) {
        cin >> A[i];
    }
    sort(A, A + 6);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> B[i];
    }
    sort(B, B + N);
    REP(i, N) {
        REP(j, 6) {
            dp[i][j] = INF;
            dp2[i][j] = INF;
        }
    }
    REP(n, 6) {
        dp[0][n] = B[0] - A[n];
    }
    FOR(i, N, 1) {
        REP(j, 6) {
            ll p = B[i] - A[j];
            REP(k, 6) {
                dp[i][j] = std::min(std::max(dp[i - 1][k], p), dp[i][j]);
            }
        }
    }
    REP(n, 6) {
        dp2[N - 1][n] = B[N - 1] - A[n];
    }
    for (ll i = N - 2; i >= 0; --i) {
        REP(j, 6) {
            ll p = B[i] - A[j];
            REP(k, 6) {
                dp2[i][j] = std::min(std::max(dp2[i][j], p), dp2[i + 1][k]);
            }
        }
    }

    ll ans = INF;
    FOR(i, N - 1, 1) {
        REP(j, 6) {
            ll p = B[i] - A[j];
            ll left = INF, right = INF;
            REP(k, 6) {
                if (p <= dp[i - 1][k])
                    left = std::min(left, dp[i - 1][k]);
                if (p <= dp2[i - 1][k])
                    right = std::min(right, dp2[i + 1][k]);
            }
            if (left == INF || right == INF)
                continue;
            ll x = std::max(left, right) - p;
            ans = std::min(ans, x);
        }
    }
    REP(i, 6) {
        ll left = INF, right = INF;
        ll p0 = B[0] - A[i];
        ll p1 = B[N - 1] - A[i];
        REP(j, 6) {
            if (p0 <= dp2[1][j])
                right = std::min(right, dp2[1][j]);
            if (p1 <= dp[N - 2][j])
                left = std::min(left, dp[N - 2][j]);
        }

        if (left < INF)
            ans = std::min(ans, left - p1);
        if (right < INF)
            ans = std::min(ans, right - p0);
    }
    cout << ans << endl;
    return 0;
}