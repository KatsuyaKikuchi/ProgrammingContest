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
    vector<vector<bool>> A(N, vector<bool>(N, false));
    REP(i, N) {
        A[i][i] = true;
    }
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        A[a][b] = true;
        A[b][a] = true;
    }
    ll p = pow(2LL, N);
    vector<ll> dp(1LL << N, INF);
    dp[0] = 0;
    REP(bit, p) {
        vector<ll> v;
        REP(i, N) {
            if ((bit >> i) & 1)
                v.push_back(i);
        }
        bool e = true;
        REP(i, v.size()) {
            FOR(j, v.size(), i + 1) {
                if (!A[v[i]][v[j]]) {
                    e = false;
                    break;
                }
            }
            if (!e)
                break;
        }
        if (e) {
            dp[bit] = 1;
            continue;
        }

        for (ll i = bit; i > 0; i = (i - 1) & bit) {
            ll j = bit & (~i);
            dp[bit] = std::min(dp[i] + dp[j], dp[bit]);
        }
    }
    cout << dp[p - 1] << endl;

    return 0;
}