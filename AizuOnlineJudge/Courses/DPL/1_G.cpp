#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll v;
    ll w;
    ll m;
};

Data D[105];
ll dp[105][10005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, W;
    cin >> N >> W;
    REP(i, N) {
        cin >> D[i].v >> D[i].w >> D[i].m;
    }
    memset(dp, 0, sizeof(dp));
    REP(i, N) {
        REP(j, D[i].w) {
            deque<ll> q;
            ll w = j;
            while (w <= W) {
                while (!q.empty() && (w - q.front()) / D[i].w > D[i].m) {
                    q.pop_front();
                }
                ll v = 0;
                if (!q.empty()) {
                    v = dp[i][q.front()] + D[i].v * ((w - q.front()) / D[i].w);
                }
                dp[i + 1][w] = std::max(dp[i][w], v);

                while (!q.empty() && dp[i][q.back()] + D[i].v * (w - q.back()) / D[i].w <= dp[i][w]) {
                    q.pop_back();
                }
                q.push_back(w);
                w += D[i].w;
            }
        }
    }

#if false
    REP(i, N) {
        REP(j, W + 1) {
            cout << dp[i + 1][j] << " ";
        }
        cout << endl;
    }
#endif

    ll ans = 0;
    REP(i, W) {
        ans = std::max(ans, dp[N][i + 1]);
    }
    cout << ans << endl;
    return 0;
}