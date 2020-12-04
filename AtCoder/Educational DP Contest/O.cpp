#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[30][30];
ll dp[25][2100000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        REP(j, N) {
            cin >> A[i][j];
        }
    }
    dp[0][0] = 1;
    ll p = pow(2LL, N);
    REP(b, p) {
        ll i = __builtin_popcount(b);
        REP(j, N) {
            if (((b >> j) & 1) == 1)
                continue;
            if (A[i][j] == 0)
                continue;
            dp[i + 1][b | (1LL << j)] += dp[i][b];
            dp[i + 1][b | (1LL << j)] %= MOD;
        }
    }
    cout << dp[N][p - 1] << endl;
    return 0;
}