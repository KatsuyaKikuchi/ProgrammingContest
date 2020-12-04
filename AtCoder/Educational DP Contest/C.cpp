#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[100005][3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        ll A[3];
        REP(j, 3) {
            cin >> A[j];
        }

        REP(j, 3) {
            dp[i + 1][j] = std::max(dp[i][(j + 1) % 3], dp[i][(j + 2) % 3]) + A[j];
        }
    }
    cout << std::max({dp[N][0], dp[N][1], dp[N][2]}) << endl;
    return 0;
}