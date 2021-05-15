#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[2005];
pll dp[2005][2005];
ll x[2] = {0, 1};
ll y[2] = {1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    ll count = H - 1 + W - 1;
    REP(i, H) {
        cin >> S[i];
    }
    REP(i, H) {
        REP(j, W) {
            dp[i][j] = pll(-INF, -INF);
        }
    }
    dp[H - 1][W - 1] = pll(0, 0);
    for (ll i = H - 1; i >= 0; --i) {
        for (ll j = W - 1; j >= 0; --j) {
            bool e = true;
            REP(n, 2) {
                ll nx = x[n] + i, ny = y[n] + j;
                if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                    continue;
                pll p = dp[nx][ny];
                ll sum = 0;
                if (S[nx][ny] == '+')
                    sum++;
                else
                    sum--;

                if ((i + j) % 2 == 0) {
                    // takahashi
                    p.first += sum;
                    if (e) {
                        e = false;
                        dp[i][j] = p;
                    }
                    else {
                        pll tt = dp[i][j];
                        if (tt.first - tt.second < p.first - p.second)
                            dp[i][j] = p;
                    }
                }
                else {
                    // aoki
                    p.second += sum;
                    if (e) {
                        e = false;
                        dp[i][j] = p;
                    }
                    else {
                        pll tt = dp[i][j];
                        if (tt.second - tt.first < p.second - p.first)
                            dp[i][j] = p;
                    }
                }
            }
        }
    }

#if false
    REP(i, H) {
        REP(j, W) {
            cout << "(" << dp[i][j].first << "," << dp[i][j].second << ") ";
        }
        cout << endl;
    }
#endif

    pll ans = dp[0][0];
    if (ans.first > ans.second)
        cout << "Takahashi" << endl;
    else if (ans.first < ans.second)
        cout << "Aoki" << endl;
    else
        cout << "Draw" << endl;
    return 0;
}