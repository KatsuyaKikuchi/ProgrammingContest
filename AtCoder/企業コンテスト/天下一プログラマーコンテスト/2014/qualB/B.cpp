#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string T[105];

ll dp[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    REP(i, N) {
        cin >> T[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    REP(i, S.length()) {
        REP(j, N) {
            ll n = T[j].length();
            if (i - n + 1 < 0)
                continue;
            string sub = S.substr(i - n + 1, n);
            if (sub == T[j])
                dp[i + 1] = (dp[i + 1] + dp[i - n + 1]) % MOD;
        }
    }

    cout << dp[S.length()] << endl;
    return 0;
}