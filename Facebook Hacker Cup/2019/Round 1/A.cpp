#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

//#define DEBUG 1
#ifdef DEBUG
#define OUT cout
#define IN cin
#else
#define OUT ws
#define IN rs
#endif

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll a;
    ll b;
    ll c;
};
struct Edge {
    ll a;
    ll b;
    ll c;
};
struct Vertex {
    vector<pll> node;
};

Vertex V[55];

struct UnionFind {
    UnionFind(int n) {
        rank.assign(n, 0);
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

    void unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        if (rank[x] < rank[y]) {
            parent[x] = y;
        }
        else {
            parent[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    vector<int> rank;
    vector<int> parent;
};

ll cost(ll s, ll g) {
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });

    vector<ll> C(55, INF);
    C[s] = 0;
    q.push(pll(s, 0));
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (t.first == g)
            return t.second;
        if (C[t.first] < t.second)
            continue;

        REP(i, V[t.first].node.size()) {
            ll n = V[t.first].node[i].first;
            ll cst = V[t.first].node[i].second + t.second;
            if (C[n] <= cst)
                continue;
            C[n] = cst;
            q.push(pll(n, cst));
        }
    }
    return INF;
}

void solve(std::ifstream &rs, std::ofstream &ws) {
    ll N, M;
    IN >> N >> M;
    REP(i, N) {
        V[i].node.clear();
    }

    vector<Data> D(M);
    REP(i, M) {
        IN >> D[i].a >> D[i].b >> D[i].c;
        D[i].a--;
        D[i].b--;
    }
    sort(D.begin(), D.end(), [](Data a, Data b) { return a.c < b.c; });

    vector<Edge> E;
    UnionFind uf(N);
    REP(i, M) {
        auto d = D[i];
        if (uf.same(d.a, d.b)) {
            if (cost(d.a, d.b) < d.c) {
                OUT << "Impossible" << endl;
                return;
            }
        }
        uf.unit(d.a, d.b);
        E.push_back(Edge{d.a, d.b, d.c});
        V[d.a].node.push_back(pll(d.b, d.c));
        V[d.b].node.push_back(pll(d.a, d.c));
    }

    OUT << E.size() << endl;
    REP(i, E.size()) {
        OUT << E[i].a + 1 << " " << E[i].b + 1 << " " << E[i].c << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    std::string rFile = "../Facebook Hacker Cup/2019/Round 1/A.txt";
    std::ifstream rs;
    rs.open(rFile, std::ios::in);

    string wFile = "../Facebook Hacker Cup/2019/Round 1/A_ans.txt";
    std::ofstream ws;
    ws.open(wFile, std::ios::out);

    ll Q;
    IN >> Q;
    REP(i, Q) {
        OUT << "Case #" << i + 1 << ": ";
        solve(rs, ws);
    }
    return 0;
}