#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
vector<ll> A;

bool check(ll m) {
    ll s = 0;
    REP(i, N) {
        s += A[i];
    }
    vector<vector<bool>> dp(N + 5, vector<bool>(m + 5, false));
    dp[0][0] = true;
    REP(i, N) {
        REP(j, m + 1) {
            dp[i + 1][j] = (dp[i + 1][j] || dp[i][j]);
            if (dp[i][j] && j + A[i] <= m) {
                dp[i + 1][j + A[i]] = true;
            }
        }
    }
    for (ll i = m; i >= 0; --i) {
        if (!dp[N][i])
            continue;

        if (s - i <= m)
            return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
    }

    ll ok = 100005, ng = -1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
    return 0;
}