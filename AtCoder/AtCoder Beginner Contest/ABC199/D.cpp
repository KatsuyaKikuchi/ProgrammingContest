#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct UnionFind {
    UnionFind(int n) {
        rank.assign(n, 0);
        count.assign(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        x = find(x);
        return count[x];
    }

    void unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        if (rank[x] < rank[y]) {
            parent[x] = y;
            count[y] += count[x];
        }
        else {
            parent[y] = x;
            count[x] += count[y];
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    vector<int> rank;
    vector<int> parent;
    vector<int> count;
};

ll C[25];
bool U[25];
vector<vector<ll>> V;
ll N, M;

ll dfs(ll index, const vector<vector<ll>> &graph) {
    if (graph.size() == index) {
        return 1;
    }

    ll ret = 0;
    REP(col, 3) {
        bool e = true;
        for (auto &nxt : graph[index]) {
            if (col == C[nxt]) {
                e = false;
                break;
            }
        }
        if (!e)
            continue;
        C[index] = col;
        ret += dfs(index + 1, graph);
        C[index] = -1;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    V.resize(N);
    UnionFind uf(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].push_back(b);
        V[b].push_back(a);
        uf.unit(a, b);
    }

    vector<vector<ll>> G(N);
    REP(i, N) {
        ll g = uf.find(i);
        G[g].push_back(i);
    }

    ll ans = 1;
    REP(i, G.size()) {
        if (G[i].size() == 0)
            continue;
        vector<vector<ll>> graph(G[i].size());
        vector<ll> I(N);
        REP(j, G[i].size()) {
            ll idx = G[i][j];
            I[idx] = j;
        }
        REP(j, G[i].size()) {
            ll idx = G[i][j];
            for (auto &nxt:V[idx]) {
                ll a = I[idx];
                ll b = I[nxt];
                graph[a].push_back(b);
            }
        }
        REP(j, N) {
            C[j] = -1;
            U[j] = false;
        }

        ans *= dfs(0, graph);
    }
    cout << ans << endl;

    return 0;
}