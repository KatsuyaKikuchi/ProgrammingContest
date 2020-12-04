#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll E[5005];
char C[2005];
ll D[2005];

ll dp[2005][2005];
bool U[2005], T[2005];

ll N, M, K, X, Y;

ll point(char my, char c) {
    if (my == c)
        return Y;

    if ((my == 'G' && c == 'C') ||
        (my == 'C' && c == 'P') ||
        (my == 'P' && c == 'G'))
        return X;
    return 0;
}

int main() {
    cin >> N >> M >> K >> X >> Y;
    REP(i, M) {
        cin >> E[i].first >> E[i].second;
        E[i].first--;
        E[i].second--;
    }
    REP(i, N) {
        cin >> C[i];
    }
    REP(i, K) {
        cin >> D[i];
        D[i]--;
    }

    memset(dp, 0, sizeof(dp));
    memset(U, 0, sizeof(U));
    U[0] = true;
    REP(i, K) {
        memset(T, 0, sizeof(T));
        REP(j, M) {
            ll a = E[j].first;
            ll b = E[j].second;
            if (U[a]) {
                dp[i + 1][a] = std::max(dp[i + 1][a], dp[i][a] + point(C[a], C[D[i]]));
                T[a] = true;
                dp[i + 1][b] = std::max(dp[i + 1][b], dp[i][a] + point(C[b], C[D[i]]));
                T[b] = true;
            }
            if (U[b]) {
                dp[i + 1][b] = std::max(dp[i + 1][b], dp[i][b] + point(C[b], C[D[i]]));
                T[b] = true;
                dp[i + 1][a] = std::max(dp[i + 1][a], dp[i][b] + point(C[a], C[D[i]]));
                T[a] = true;
            }
        }
        REP(j, N) {
            U[j] = T[j];
        }
    }

    ll max = 0;
    REP(i, N) {
        max = std::max(max, dp[K][i]);
    }
    cout << max << endl;
    return 0;
}