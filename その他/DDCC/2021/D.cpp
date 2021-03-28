#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(vector<ll> &B, vector<ll> &P) {
    ll N = B.size();
    ll M = 10;
    REP(i, N) {
        M += B[i];
    }

    ll b = pow(2LL, N);
    vector<vector<ll>> dp(b, vector<ll>(M + 1, -INF));
    dp[0][10] = 0;
    REP(bit, b) {
        REP(i, M + 1) {
            if (dp[bit][i] == -INF)
                continue;
            vector<bool> used(N, false);
            REP(j, N) {
                if ((bit >> j) & 1)
                    used[j] = true;
            }
            REP(j, N) {
                if (used[j])
                    continue;
                if (B[j] > i)
                    continue;

                ll num = i - B[j];
                ll p = P[j];
                ll nxt = (bit | (1LL << j));
                if (j - 2 >= 0 && used[j - 2]) {
                    if (!used[j - 1]) {
                        nxt = (nxt | (1LL << (j - 1)));
                        p += P[j - 1];
                    }
                }
                if (j + 2 < N && used[j + 2]) {
                    if (!used[j + 1]) {
                        nxt = (nxt | (1LL << (j + 1)));
                        p += P[j + 1];
                    }
                }

                if (num == 0) {
                    num += p;
                }

                dp[nxt][num] = std::max(dp[nxt][num], dp[bit][i] + p);
            }
        }
    }

    ll ret = 0;
    REP(i, b) {
        REP(j, M + 1) {
            ret = std::max(ret, dp[i][j] + j);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<ll> a0 = {6, 3, 4, 5, 8, 5, 9, 3, 1, 7};
    vector<ll> a1 = {5, 10, 6, 4, 9, 1, 7, 8, 4, 3};

    vector<ll> b0 = {10, 7, 5, 7, 3, 2, 4, 4, 3, 8};
    vector<ll> b1 = {8, 1, 5, 6, 9, 8, 8, 4, 1, 3};

    vector<ll> c0 = {12, 7, 6, 4, 6, 11, 2, 9, 2, 15};
    vector<ll> c1 = {2, 6, 10, 1, 8, 4, 2, 2, 9, 5};

    vector<ll> ans;
    ans.push_back(solve(a0, a1));
    ans.push_back(solve(b0, b1));
    ans.push_back(solve(c0, c1));
    REP(i, ans.size()) {
        cout << ans[i];
        if (i < ans.size() - 1)
            cout << ",";
    }
    cout << endl;

    return 0;
}