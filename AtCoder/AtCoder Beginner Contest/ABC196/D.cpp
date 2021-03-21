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
    ll p = pow(2LL, H * W);
    vector<vector<vector<ll>>> dp(p, vector<vector<ll>>(A + 1, vector<ll>(B + 1, 0)));
    dp[0][0][0] = 1;
    REP(h, H) {
        REP(w, W) {
            ll idx = h * W + w;
            REP(bit, p) {
                REP(a, A + 1) {
                    REP(b, B + 1) {
                        if (a < A) {
                            if (w < W - 1) {
                                ll x = (1LL << idx);
                                ll y = (1LL << (idx + 1));
                                if ((bit & x) == 0 && (bit & y) == 0) {
                                    ll nxt = (bit | x | y);
                                    dp[nxt][a + 1][b] += dp[bit][a][b];
                                }
                            }
                            if (h < H - 1) {
                                ll x = (1LL << idx);
                                ll y = (1LL << (idx + W));
                                if ((bit & x) == 0 && (bit & y) == 0) {
                                    ll nxt = (bit | x | y);
                                    dp[nxt][a + 1][b] += dp[bit][a][b];
                                }
                            }
                        }
                        if (b < B) {
                            if (((bit >> idx) & 1) == 0) {
                                ll nxt = (bit | (1LL << idx));
                                dp[nxt][a][b + 1] += dp[bit][a][b];
                            }
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;
    REP(i, p) {
        ans += dp[i][A][B];
    }
    cout << ans << endl;
    return 0;
}