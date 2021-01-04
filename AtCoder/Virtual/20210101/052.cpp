#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
ll dp[60][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }
    memset(dp, -1, sizeof(dp));
    vector<ll> bit;
    while (K > 0) {
        bit.push_back(K % 2);
        K /= 2;
    }
    while (bit.size() < 50) {
        bit.push_back(0);
    }
    dp[0][0] = 0;
    reverse(bit.begin(), bit.end());
    REP(i, bit.size()) {
        vector<ll> v(2, 0);
        ll b = bit.size() - i - 1;
        ll p = pow(2LL, b);
        REP(j, N) {
            REP(k, 2) {
                if (((A[j] >> b) & 1) != k)
                    v[k] += p;
            }
        }

        dp[i + 1][0] = dp[i][0] + v[bit[i]];
        if (dp[i][1] >= 0)
            dp[i + 1][1] = dp[i][1] + std::max(v[0], v[1]);
        if (bit[i] == 1)
            dp[i + 1][1] = std::max(dp[i + 1][1], dp[i][0] + v[0]);
    }

    cout << std::max(dp[bit.size()][0], dp[bit.size()][1]) << endl;

    return 0;
}