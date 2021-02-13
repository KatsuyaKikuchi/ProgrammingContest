#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, Y, Z;
    cin >> N >> M >> Y >> Z;
    vector<ll> P(M);
    std::unordered_map<char, ll> C;
    REP(i, M) {
        char c;
        cin >> c >> P[i];
        C[c] = i;
    }
    string S;
    cin >> S;
    ll bit = pow(2LL, M);
    vector<vector<vector<ll>>> dp(N + 5, vector<vector<ll>>(M + 5, vector<ll>(bit + 5, -INF)));
    dp[0][M][0] = 0;
    REP(i, N) {
        ll idx = C[S[i]];
        REP(j, M + 1) {
            REP(b, bit) {
                dp[i + 1][j][b] = std::max(dp[i + 1][j][b], dp[i][j][b]);
                ll cost = dp[i][j][b] + P[idx];
                if (j == idx)
                    cost += Y;
                ll b0 = (b | (1LL << idx));
                dp[i + 1][idx][b0] = std::max(dp[i + 1][idx][b0], cost);
            }
        }
    }

    ll ans = -INF;
    REP(i, M + 1) {
        REP(j, bit - 1) {
            ans = std::max(ans, dp[N][i][j]);
        }
        ans = std::max(ans, dp[N][i][bit - 1] + Z);
    }
    cout << ans << endl;
    return 0;
}