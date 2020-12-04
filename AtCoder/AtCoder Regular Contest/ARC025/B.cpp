#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll B[105][105];
ll W[105][105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    memset(B, 0, sizeof(B));
    memset(W, 0, sizeof(W));
    REP(i, N) {
        REP(j, M) {
            ll a;
            cin >> a;
            if ((i + j) % 2 == 0)
                B[i][j] = a;
            else
                W[i][j] = a;
        }
    }

    REP(i, N) {
        REP(j, M) {
            B[i][j + 1] += B[i][j];
            W[i][j + 1] += W[i][j];
        }
    }
    REP(j, M) {
        REP(i, N) {
            B[i + 1][j] += B[i][j];
            W[i + 1][j] += W[i][j];
        }
    }
    REP(i, N) {
        REP(j, M) {
            B[i][j] -= W[i][j];
        }
    }

    ll ans = 0;
    REP(i, N) {
        REP(j, M) {
            REP(h, i + 1) {
                REP(w, j + 1) {
                    ll sb = B[i][j];
                    if (h > 0)
                        sb -= B[h - 1][j];
                    if (w > 0)
                        sb -= B[i][w - 1];
                    if (h > 0 && w > 0)
                        sb += B[h - 1][w - 1];
                    if (sb == 0)
                        ans = std::max(ans, (i - h + 1) * (j - w + 1));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}