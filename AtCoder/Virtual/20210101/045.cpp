#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[105][105];

ll len(string s, string t) {
    ll N = s.length();
    ll M = t.length();
    REP(i, N + 1) {
        REP(j, M + 1) {
            dp[i][j] = 0;
        }
    }
    REP(i, N) {
        REP(j, M) {
            dp[i + 1][j + 1] = std::max({dp[i][j + 1], dp[i + 1][j]});
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = std::max({dp[i][j] + 1, dp[i + 1][j + 1]});
            }
        }
    }

    return dp[N][M];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string S;
    cin >> N >> S;
    ll ans = N;
    REP(i, N) {
        string s = "";
        string t = "";
        REP(j, i) {
            s.push_back(S[j]);
        }
        FOR(j, N, i) {
            t.push_back(S[j]);
        }

        ll l = len(s, t);
        ans = std::min(ans, N - l * 2);
    }
    cout << ans << endl;

    return 0;
}