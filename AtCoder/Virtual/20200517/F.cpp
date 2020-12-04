#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[2005];
ll dp[2005][2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X;
    cin >> N >> X;
    REP(i, N) {
        cin >> A[i];
    }

    ll mx = 0;
    REP(i, N) {
        ll mn = A[i];
        REP(j, N) {
            mn = std::min(mn, A[(N + i - j) % N]);
            dp[i][j] = mn;
        }
    }

    ll ans = INF;
    REP(i, N) {
        ll s = i * X;
        REP(j, N) {
            s += dp[j][i];
        }
        ans = std::min(ans, s);
    }
    cout << ans << endl;
    return 0;
}