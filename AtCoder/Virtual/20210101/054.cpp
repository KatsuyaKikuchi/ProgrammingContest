#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> P(N, 0), C(N, 0);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        C[a] |= (1LL << b);
        P[b] |= (1LL << a);
    }

    ll p = pow(2LL, N);
    vector<ll> dp(1LL << N, 0);
    dp[0] = 1;
    FOR(b, p, 1) {
        REP(i, N) {
            if (((b >> i) & 1) == 0)
                continue;
            if ((b & P[i]) == 0 && (b & C[i]) == C[i]) {
                dp[b] += dp[b & (~(1LL << i))];
            }
        }
    }
    cout << dp[p - 1] << endl;
    return 0;
}