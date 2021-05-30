#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll solve(vector<ll> &A, ll K) {
    ll N = A.size();
    A.push_back(0);
    sort(A.begin(), A.end(), greater<ll>());
    // 操作回数
    ll MAX = 40;
    // [i番目に][操作回数j回で]　= 辿り着くために消す草の数最小値
    vector<vector<ll>> dp(N + 5, vector<ll>(MAX + 2, INF));
    dp[0][0] = 0;
    REP(i, N) {
        REP(j, MAX) {
            dp[i + 1][j] = std::min(dp[i][j] + 1, dp[i + 1][j]);
            ll nxt = i, ng = N;
            while (abs(nxt - ng) > 1) {
                ll mid = (nxt + ng) / 2;
                if (A[mid] >= A[i] / 2 + 1)
                    nxt = mid;
                else
                    ng = mid;
            }
            dp[nxt + 1][j + 1] = std::min(dp[nxt + 1][j + 1], dp[i][j]);
        }
    }

    REP(i, MAX) {
        ll m = dp[N][i];
        if (m <= K) {
            return pll(i, m);
        }
    }
    return pll(INF, INF);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    vector<ll> A;
    REP(i, N) {
        ll a;
        cin >> a;
        A.push_back(a);
    }

    pll ans = solve(A, K);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}