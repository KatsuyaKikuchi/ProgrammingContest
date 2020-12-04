#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct LowestCommonAncestor {
    const int MAX_LOG_V = 50;

    vector<vector<int> > G, parent;
    int root = 0, V;
    vector<int> depth;

    LowestCommonAncestor() {}

    LowestCommonAncestor(int V) : V(V) { init(); }

    void init() {
        for (int i = 0; i < (int) G.size(); i++)
            G[i].clear();
        G.clear();
        for (int i = 0; i < (int) parent.size(); i++)
            parent[i].clear();
        parent.clear();
        depth.clear();
        G.resize(V);
        parent.resize(MAX_LOG_V, vector<int>(V));
        depth.resize(V);
    }

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void dfs(int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for (int i = 0; i < (int) G[v].size(); i++) {
            if (G[v][i] != p)
                dfs(G[v][i], v, d + 1);
        }
    }

    void construct() {
        dfs(root, -1, 0);
        for (int k = 0; k + 1 < MAX_LOG_V; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0)
                    parent[k + 1][v] = -1;
                else
                    parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] > depth[v])
            swap(u, v);
        for (int k = 0; k < MAX_LOG_V; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v)
            return u;
        for (int k = MAX_LOG_V - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};

int main() {
    ll N;
    cin >> N;
    LowestCommonAncestor lca(N);
    ll root = 0;
    REP(i, N) {
        ll p;
        cin >> p;
        if (p < 0) {
            root = i;
            continue;
        }
        lca.add_edge(p - 1, i);
    }
    lca.root = root;

    lca.construct();

    ll Q;
    cin >> Q;
    REP(q, Q) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        ll p = lca.lca(a, b);
        if (p == b)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}