#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[5005];
ll dp[5005][5005];

int main() {
    ll N, P;
    cin >> N >> P;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A + N, [](pll a, pll b) { return a.first > b.first; });
    memset(dp, 0, sizeof(dp));
    REP(i, N) {
        REP(j, P + 1) {
            dp[i + 1][j] = dp[i][j];
            if (j - A[i].first >= 0)
                dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j - A[i].first] + A[i].second);
        }
    }

    ll ans = 0;
    REP(i, N) {
        //! 一番安いお菓子としてiを選ぶ
        REP(j, P + 1) {
            ll s = dp[i][j] + A[i].second;
            ans = std::max(ans, s);
        }
    }
    cout << ans << endl;
    return 0;
}