#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[405][405];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(2 * N);
    REP(i, A.size()) {
        cin >> A[i];
    }
    REP(i, 2 * N) {
        REP(j, 2 * N) {
            dp[i][j] = INF;
        }
    }
    REP(i, 2 * N - 1) {
        dp[i][i + 1] = abs(A[i] - A[i + 1]);
    }
    FOR(len, 2 * N + 1, 1) {
        REP(left, 2 * N) {
            ll right = left + len;
            if (right >= 2 * N)
                break;
            dp[left][right] = std::min(dp[left][right], dp[left + 1][right - 1] + abs(A[left] - A[right]));
            for (ll mid = left + 1; mid < right; mid += 2) {
                dp[left][right] = std::min(dp[left][right], dp[left][mid] + dp[mid + 1][right]);
            }
        }
    }
#if false
    REP(i, 2 * N) {
        FOR(j, 2 * N, i + 1) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
#endif
    cout << dp[0][2 * N - 1];
    return 0;
}