#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[105][100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<ll> v0, v1;
    for (ll i = 1; i * i <= N; ++i) {
        v0.push_back(i);
    }
    ll last = N;
    REP(i, v0.size()) {
        if (last <= v0.size())
            break;
        ll n = v0[i];
        ll m = std::max((N / (n + 1)) + 1, (ll) v0.size());

        v1.push_back(std::max(0LL, last - m + 1));
        last = m - 1;
    }
    reverse(v0.begin(), v0.end());
    memset(dp, 0, sizeof(dp));
    REP(i, v1.size()) {
        dp[1][i] = v1[i];
    }
    REP(i, v0.size()) {
        dp[1][v1.size() + i] = 1;
    }

    FOR(i, K, 1) {
        ll s = 0;
        ll index = v1.size() + v0.size() - 1;
        REP(j, v1.size()) {
            s = (s + dp[i][index--]) % MOD;
            dp[i + 1][j] = (s * v1[j]) % MOD;
        }
        REP(j, v0.size()) {
            s = (s + dp[i][index--]) % MOD;
            dp[i + 1][j + v1.size()] = s;
        }
    }

    ll ans = 0;
    REP(i, v0.size() + v1.size()) {
        ans = (dp[K][i] + ans) % MOD;
    }
    cout << ans << endl;
    return 0;
}