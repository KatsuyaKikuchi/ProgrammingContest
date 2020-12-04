#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[505];
pll dp[505][505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        dp[i][i] = pll(0, A[i]);
    }

    FOR(i, N, 1) {
        REP(j, N) {
            if (j + i >= N)
                break;
            dp[j][j + i] = pll(0, -1);
            for (ll k = j; k < j + i; ++k) {
                pll l = dp[j][k];
                pll r = dp[k + 1][j + i];
                ll n = -1;
                ll m = l.first + r.first;
                if (l.second == r.second && l.second >= 0 && r.second >= 0) {
                    n = l.second + 1;
                    m++;
                }

                if (dp[j][j + i].first < m)
                    dp[j][j + i] = pll(m, n);
            }
        }
    }

    cout << N - dp[0][N - 1].first << endl;
    return 0;
}