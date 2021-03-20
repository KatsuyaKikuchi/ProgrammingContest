#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, A, B;
    cin >> H >> W >> A >> B;
    if (H == 1) {
        vector<vector<vector<ll>>> dp(W + 2, vector<vector<ll>>(A + 1, vector<ll>(B + 1, 0)));
        dp[0][0][0] = 1;
        REP(w, W) {
            REP(a, A + 1) {
                REP(b, B + 1) {
                    if (a < A) {
                        //! Aをおく
                        dp[w + 2][a + 1][b] += dp[w][a][b];
                    }
                    if (b < B) {
                        //! Bをおく
                        dp[w + 1][a][b + 1] += dp[w][a][b];
                    }
                    {
                        //! 何も置かない
                        dp[w + 1][a][b] += dp[w][a][b];
                    }
                }
            }
        }
        cout << dp[W][A][B] << endl;
        return 0;
    }
    ll bit = pow(4LL, W);
    vector<vector<vector<vector<ll>>>> dp(H * W + 1, vector<vector<vector<ll>>>(bit + 1, vector<vector<ll>>(A + 1,
                                                                                                            vector<ll>(
                                                                                                                    B +
                                                                                                                    1,
                                                                                                                    0))));
    dp[0][0][0][0] = 1;
    ll p = bit / 4;
    // 0 = 何も置いていない
    // 1 = aが横
    // 2 = aが縦
    // 3 = b
    // 4 = なんか埋まってる
    REP(h, H) {
        REP(w, W) {
            ll nxt = h * W + w;
            REP(bt, bit) {
                REP(a, A + 1) {
                    REP(b, B + 1) {
                        if (a < A && (bt % 4) != 2 && (bt / p) != 1) {
                            //! Aをおく
                            if (w < W - 1 && (bt % 16) / 4 != 2) {
                                //! 横に置く
                                ll nbit = bt / 4 + p * 1;
                                dp[nxt + 1][nbit][a + 1][b] += dp[nxt][bt][a][b];
                            }
                            if (h < H - 1) {
                                //! 縦に置く
                                ll nbit = bt / 4 + p * 2;
                                dp[nxt + 1][nbit][a + 1][b] += dp[nxt][bt][a][b];
                            }
                        }
                        if (b < B && (bt % 4) != 2 && (bt / p) != 1) {
                            //! Bをおく
                            ll nbit = bt / 4 + p * 3;
                            dp[nxt + 1][nbit][a][b + 1] += dp[nxt][bt][a][b];
                        }
                        {
                            //! 何も置かない
                            dp[nxt + 1][bt / 4][a][b] += dp[nxt][bt][a][b];
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;
    REP(i, bit) {
        // cout << i % 4 << " " << i / 4 << " " << dp[H * W][i][A][B] << endl;
        ans += dp[H * W][i][A][B];
    }
    cout << ans << endl;
    return 0;
}