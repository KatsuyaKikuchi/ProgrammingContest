#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<ll> v[15];
ll dp[15][2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        ll c, d;
        cin >> c >> d;
        d--;
        v[d].push_back(c);
    }

    REP(i, 10) {
        sort(v[i].begin(), v[i].end(), greater<ll>());
    }
    memset(dp, 0, sizeof(dp));
    REP(i, 10) {
        REP(j, K + 1) {
            ll s = 0;
            dp[i + 1][j] = dp[i][j];
            REP(k, v[i].size()) {
                if (j - (k + 1) < 0)
                    break;
                s += v[i][k];
                dp[i + 1][j] = std::max({dp[i + 1][j], dp[i][j], dp[i][j - (k + 1)] + s + (k + 1) * (k)});
            }
        }
    }

    cout << dp[10][K] << endl;

    return 0;
}