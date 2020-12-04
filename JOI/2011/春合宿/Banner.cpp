#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll M[405][405];
ll S[405][405][3][3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> M[i][j];
        }
    }
    memset(S, 0, sizeof(S));
    ll ans = 0;
    REP(i, H) {
        REP(l, W) {
            FOR(r, W, l + 1) {
                ll a = M[i][l];
                ll b = M[i][r];

                if (a == b) {
                    if (a == 0) {
                        ans += S[l][r][1][2];
                        ans += S[l][r][2][1];
                    }
                    if (a == 1) {
                        ans += S[l][r][0][2];
                        ans += S[l][r][2][0];
                    }
                    if (a == 2) {
                        ans += S[l][r][0][1];
                        ans += S[l][r][1][0];
                    }
                }
                else {
                    ll m = 0;
                    REP(j, 3) {
                        if (a != j && b != j)
                            m = j;
                    }
                    REP(j, 3) {
                        ans += S[l][r][m][j];
                        if (m != j)
                            ans += S[l][r][j][m];
                    }
                }

                S[l][r][a][b]++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}