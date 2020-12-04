#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<pll> node;
};

Vertex T[100005];
Vertex V[20];
ll A[20];
ll C[100005];
ll dp[150000][20];
ll Cost[20][20];

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
        T[a].node.push_back(pll(b, 1));
        T[b].node.push_back(pll(a, 1));
    }
    cin >> A[0];
    A[0]--;
    ll K;
    cin >> K;
    REP(i, K) {
        cin >> A[i + 1];
        A[i + 1]--;
    }
    K++;
    REP(i, K) {
        REP(j, N) {
            C[j] = INF;
        }
        C[A[i]] = 0;
        queue<pll> q;
        q.push(pll(A[i], 0));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            for (auto &n : T[t.first].node) {
                if (C[n.first] <= cost)
                    continue;
                C[n.first] = cost;
                q.push(pll(n.first, cost));
            }
        }

        REP(j, K) {
            Cost[i][j] = C[A[j]];
        }
    }

#if false
    REP(i, K + 1) {
        ll index = 0;
        REP(j, K + 1) {
            if (i == j)
                cout << 0 << " ";
            else
                cout << V[i].node[index++].second << " ";
        }
        cout << endl;
    }
#endif

    ll p = pow(2LL, K);
    REP(i, p) {
        REP(j, K) {
            dp[i][j] = INF;
        }
    }
    dp[1][0] = 0;
    REP(i, p) {
        REP(j, K) {
            ll n = i & (~(1LL << j));
            ll cost = INF;
            REP(k, K) {
                if (((n >> k) & 1) == 0)
                    continue;
                cost = std::min(dp[n][k] + Cost[j][k], cost);
            }
            dp[i][j] = std::min(dp[i][j], cost);
        }
    }
    ll ans = INF;
    REP(i, K - 1) {
        ans = std::min(ans, dp[p - 1][i + 1]);
    }
    cout << ans << endl;

    return 0;
}