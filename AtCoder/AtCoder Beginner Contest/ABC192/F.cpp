#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18 + 10;

ll N, X;
ll A[105];
ll S[105][105][105][105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> X;
    REP(i, N) {
        cin >> A[i];
    }
    memset(S, -1, sizeof(S));

    FOR(i, N + 1, 1) {
        S[0][0][i][X % i] = 0;
    }
    REP(i, N) {
        REP(j, i + 1) {
            FOR(a, N + 1, 1) {
                REP(b, N + 1) {
                    S[i + 1][j][a][b] = std::max(S[i + 1][j][a][b], S[i][j][a][b]);
                    if (S[i][j][a][b] < 0)
                        continue;
                    ll s = S[i][j][a][b] + A[i];
                    ll p = (X - s) % a;
                    S[i + 1][j + 1][a][p] = std::max(S[i + 1][j + 1][a][p], s);
                }
            }
        }
    }

    ll ans = INF;
    FOR(i, N + 1, 1) {
        if (S[N][i][i][0] < 0)
            continue;
        ans = std::min(ans, (X - S[N][i][i][0]) / i);
    }
    cout << ans << endl;
    return 0;
}