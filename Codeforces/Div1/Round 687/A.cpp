#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N, P, K;
    cin >> N >> P >> K;
    string S;
    cin >> S;
    ll X, Y;
    cin >> X >> Y;

    vector<ll> dp(N + 1, INF);
    dp[N] = 0;
    for (ll i = N - 1; i >= 0; --i) {
        ll n = std::min(N, i + K);
        ll m = dp[n];
        if (n < N && S[n] == '0')
            m += X;
        dp[i] = m;
    }
    ll ret = INF;
    REP(i, N) {
        if (i + P - 1 >= N)
            break;
        ll m = dp[i + P - 1] + i * Y;
        if (S[i + P - 1] == '0')
            m += X;
        ret = std::min(ret, m);
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}