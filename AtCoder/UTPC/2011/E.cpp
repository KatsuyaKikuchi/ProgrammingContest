#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[1005];
ll dp[1005][1005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A + N, [](pll a, pll b) { return a.second - a.first < b.second - b.first; });

    REP(i, N + 1) {
        REP(j, N + 1) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    REP(i, N) {
        REP(j, N + 1) {
            dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);
            if (j > 0) {
                ll t = A[i].first + dp[i][j - 1];
                if (t <= A[i].second)
                    dp[i + 1][j] = std::min(dp[i + 1][j], t);
            }
        }
    }

    ll ans = 0;
    REP(i, N + 1) {
        if (dp[N][i] < INF)
            ans = std::max(ans, i);
    }
    cout << ans << endl;
    return 0;
}