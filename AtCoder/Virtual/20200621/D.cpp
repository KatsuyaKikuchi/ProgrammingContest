#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[10][100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    A.push_back(INF);
    sort(A.begin(), A.end());
    memset(dp, 0, sizeof(dp));
    REP(i, N) {
        dp[0][N - 1 - i] = dp[0][N - i] + 1;
    }

    REP(i, 3) {
        REP(j, N) {
            ll idx = lower_bound(A.begin(), A.end(), A[j] * 2LL) - A.begin();
            dp[i + 1][j] = dp[i][idx];
        }
        REP(j, N) {
            dp[i + 1][N - 1 - j] += dp[i + 1][N - j];
            dp[i + 1][N - 1 - j] %= MOD;
        }
    }

    cout << dp[3][0] << endl;
    return 0;
}