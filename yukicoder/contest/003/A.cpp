#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[100005];

ll bitnum(ll n) {
    ll num = 0;
    while (n > 0) {
        num += (n & 1);
        n >>= 1;
    }
    return num;
}

int main() {
    ll N;
    cin >> N;
    REP(i, N + 1) {
        dp[i] = INF;
    }
    dp[1] = 1;

    queue<ll> q;
    q.push(1);
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        ll n = bitnum(t);

        if (t - n > 0 && dp[t - n] > dp[t] + 1) {
            dp[t - n] = dp[t] + 1;
            q.push(t - n);
        }

        if (t + n <= N && dp[t + n] > dp[t] + 1) {
            dp[t + n] = dp[t] + 1;
            q.push(t + n);
        }
    }

    if (dp[N] == INF)
        cout << -1 << endl;
    else
        cout << dp[N] << endl;
    return 0;
}