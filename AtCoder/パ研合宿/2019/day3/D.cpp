#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[1005][5];
string S[5];
char C[3] = {'R', 'B', 'W'};

int main() {
    ll N;
    cin >> N;
    REP(i, 5) {
        cin >> S[i];
    }

    REP(i, N + 1) {
        REP(j, 5) {
            dp[i][j] = INF;
        }
    }

    REP(i, 5) {
        dp[0][i] = 0;
    }

    REP(i, N) {
        REP(c, 3) {
            ll t = 0;
            REP(j, 5) {
                if (S[j][i] != C[c])
                    t++;
            }
            dp[i + 1][c] = std::min(dp[i][(c + 1) % 3], dp[i][(c + 2) % 3]) + t;
        }
    }

    ll ans = INF;
    REP(i, 3) {
        ans = std::min(dp[N][i], ans);
    }
    cout << ans << endl;
    return 0;
}