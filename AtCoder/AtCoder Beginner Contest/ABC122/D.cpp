#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string A[4] = {"A", "C", "G", "T"};
//! [入れる文字][1文字前][2文字前]
ll dp[105][5][5][5];

int main() {
    ll N;
    cin >> N;
    memset(dp, 0, sizeof(dp));
    REP(i, 4) {
        REP(j, 4) {
            REP(k, 4) {
                string s = A[i] + A[j] + A[k];
                if (s == "AGC" || s == "ACG" || s == "GAC")
                    continue;
                dp[3][k][j][i] = 1;
            }
        }
    }

    for (ll i = 4; i <= N; ++i) {
        REP(a, 4) {
            REP(b, 4) {
                REP(c, 4) {

                    REP(j, 4) {
                        string s = A[b] + A[c] + A[j];
                        if (s == "GAC" || s == "AGC" || s == "ACG")
                            continue;
                        string t = A[c] + A[j];
                        if (t == "GC" && A[a] == "A")
                            continue;
                        string r = A[a] + A[b];
                        if (r == "AG" && A[j] == "C")
                            continue;
                        dp[i][j][c][b] += dp[i - 1][c][b][a];
                        dp[i][j][c][b] %= MOD;
                    }
                }
            }
        }
    }

    ll ans = 0;
    REP(i, 4) {
        REP(j, 4) {
            REP(k, 4) {
                ans += dp[N][i][j][k];
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;
    return 0;
}