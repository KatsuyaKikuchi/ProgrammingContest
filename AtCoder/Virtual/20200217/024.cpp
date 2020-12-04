#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[105];
ll B[105];
ll dp[1005][1005];
ll dpA[105][1005];
ll dpB[105][1005];

int main() {
    ll N, M;
    cin >> N >> M;
    ll sa = 0, sb = 0;
    REP(i, N) {
        cin >> A[i];
        sa += A[i];
    }
    REP(i, M) {
        cin >> B[i];
        sb += B[i];
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    FOR(i, 1001, 1) {
        REP(j, 1001) {
            dp[i][j] = dp[i - 1][j];
            if (j - i >= 0)
                dp[i][j] += dp[i][j - i];
            dp[i][j] %= MOD;
        }
    }

    vector<ll> va, vb;
    {
        ll n = 1;
        FOR(i, N, 1) {
            if (A[i] != A[i - 1]) {
                va.push_back(n);
                n = 0;
            }
            n++;
        }
        va.push_back(n);
    }
    {
        ll n = 1;
        FOR(i, M, 1) {
            if (B[i] != B[i - 1]) {
                vb.push_back(n);
                n = 0;
            }
            n++;
        }
        vb.push_back(n);
    }
    memset(dpA, 0, sizeof(dpA));
    memset(dpB, 0, sizeof(dpB));
    dpA[0][0] = 1;
    REP(i, va.size()) {
        REP(j, sb + 1) {
            REP(k, j + 1) {
                dpA[i + 1][j] += dpA[i][j - k] * dp[va[i]][k];
                dpA[i + 1][j] %= MOD;
            }
        }
    }
    dpB[0][0] = 1;
    REP(i, vb.size()) {
        REP(j, sa + 1) {
            REP(k, j + 1) {
                dpB[i + 1][j] += dpB[i][j - k] * dp[vb[i]][k];
                dpB[i + 1][j] %= MOD;
            }
        }
    }

    cout << (dpA[va.size()][sb] * dpB[vb.size()][sa]) % MOD << endl;
    return 0;
}