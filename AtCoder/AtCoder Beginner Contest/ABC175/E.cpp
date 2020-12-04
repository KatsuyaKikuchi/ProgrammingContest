#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[3005][3005][5];
ll A[3005][3005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll R, C, N;
    cin >> R >> C >> N;

    memset(S, 0, sizeof(S));
    memset(A, 0, sizeof(A));
    REP(i, N) {
        ll r, c, v;
        cin >> r >> c >> v;
        r--;
        c--;
        A[r][c] = v;
    }

    REP(i, R) {
        REP(j, C) {
            for (ll k = 3; k >= 0; --k) {
                if (j > 0)
                    S[i][j][k] = std::max(S[i][j][k], S[i][j - 1][k]);
            }
            for (ll k = 3; k >= 0; --k) {
                if (k > 0)
                    S[i][j][k] = std::max(S[i][j][k], S[i][j][k - 1] + A[i][j]);
                S[i + 1][j][0] = std::max(S[i + 1][j][0], S[i][j][k]);
            }
        }
    }

    ll ans = 0;
    REP(i, 4) {
        ans = std::max(S[R - 1][C - 1][i], ans);
    }
    cout << ans << endl;
    return 0;
}