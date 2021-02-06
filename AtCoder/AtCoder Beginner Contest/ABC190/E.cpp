#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[20];

struct Vertex {
    vector<ll> node;
};
Vertex V[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    ll K;
    cin >> K;
    REP(i, K) {
        cin >> C[i];
        C[i]--;
    }
    ll p = pow(2LL, K);
    vector<vector<ll>> dp(K, vector<ll>(p, INF));
    vector<vector<ll>> D(K, vector<ll>(K, INF));

    REP(i, K) {
        vector<ll> dst(N, INF);
        dst[C[i]] = 0;
        queue<pll> q;
        q.push(pll(C[i], 0));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            REP(j, V[t.first].node.size()) {
                ll nxt = V[t.first].node[j];
                if (dst[nxt] <= cost)
                    continue;
                dst[nxt] = cost;
                q.push(pll(nxt, cost));
            }
        }
        REP(j, K) {
            D[i][j] = dst[C[j]];
        }
    }
    REP(i, K) {
        dp[i][pow(2LL, i)] = 1;
    }
    REP(bit, p) {
        REP(i, K) {
            if (((bit >> i) & 1) == 0)
                continue;
            REP(j, K) {
                ll b = 1LL << j;
                if (bit & b)
                    continue;
                ll dist = D[i][j];
                dp[j][bit | b] = std::min(dp[j][bit | b], dp[i][bit] + dist);
            }
        }
    }

    ll ans = INF;
    REP(i, K) {
        ans = std::min(ans, dp[i][p - 1]);
    }
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}