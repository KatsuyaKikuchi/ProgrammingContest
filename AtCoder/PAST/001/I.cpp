#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll D[1005];

ll dp[1005][2000];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        string s;
        cin >> s;
        ll bit = 0;
        REP(i, N) {
            if (s[i] == 'Y')
                bit |= (1 << i);
        }
        cin >> D[i].second;
        D[i].first = bit;
    }

    ll p = pow(2, N);
    REP(i, M + 1) {
        REP(j, p) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    REP(i, M) {
        REP(j, p) {
            dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);
            ll b = (j | D[i].first);
            dp[i + 1][b] = std::min(dp[i + 1][b], dp[i][j] + D[i].second);
        }

    }

    if (dp[M][p - 1] == INF)
        cout << -1 << endl;
    else
        cout << dp[M][p - 1] << endl;
    return 0;
}