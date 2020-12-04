#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct RootedTree {
    RootedTree(int n, int root = 0) :
            mRoot(root) {
        mVertexTbl.resize(n);
    }

    void addEdge(int a, int b, long long int cost = 1) {
        mVertexTbl[a].child.push_back(pair<int, long long int>(b, cost));
        mVertexTbl[b].child.push_back(pair<int, long long int>(a, cost));
    }

    void build() {
        queue<tuple<int, int, long long int>> q;
        q.push(make_tuple(mRoot, -1, 0));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int index = get<0>(t);
            int parent = get<1>(t);
            long long int depth = get<2>(t);
            mVertexTbl[index].parent = parent;
            mVertexTbl[index].depth = depth;
            for (auto it = mVertexTbl[index].child.begin(); it != mVertexTbl[index].child.end();) {
                int nxt = (*it).first;
                if (nxt == parent) {
                    mVertexTbl[index].child.erase(it);
                    continue;
                }
                q.push(make_tuple(nxt, index, depth + (*it).second));
                ++it;
            }
        }

        for (auto &v:mVertexTbl) {
            for (int i = 0; i < Vertex::MAX; ++i) {
                v.doubling[i] = -1;
            }
            v.doubling[0] = v.parent;
        }

        for (int d = 1; d < Vertex::MAX; ++d) {
            for (auto &v:mVertexTbl) {
                int p = v.doubling[d - 1];
                if (p < 0)
                    continue;
                v.doubling[d] = mVertexTbl[p].doubling[d - 1];
            }
        }
    }

    int lca(int u, int v) {
        if (mVertexTbl[u].depth < mVertexTbl[v].depth)
            swap(u, v);
        ll d = mVertexTbl[u].depth - mVertexTbl[v].depth;
        for (int i = 0; i < Vertex::MAX; ++i) {
            if ((d >> i) & 1)
                u = mVertexTbl[u].doubling[i];
        }

        if (u == v)
            return u;

        for (int i = Vertex::MAX - 1; i >= 0; --i) {
            if (mVertexTbl[u].doubling[i] == mVertexTbl[v].doubling[i])
                continue;
            u = mVertexTbl[u].doubling[i];
            v = mVertexTbl[v].doubling[i];
        }

        return mVertexTbl[u].parent;
    }

    struct Vertex {
        static const int MAX = 55;

        vector<pair<int, long long int>> child;
        long long int depth = 0;
        int parent = -1;
        int doubling[MAX];
    };

    int mRoot;
    vector<Vertex> mVertexTbl;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    RootedTree tree(N);
    REP(i, N) {
        ll k;
        cin >> k;
        REP(_, k) {
            ll n;
            cin >> n;
            tree.addEdge(i, n, 1);
        }
    }

    tree.build();
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll u, v;
        cin >> u >> v;
        cout << tree.lca(u, v) << endl;
    }
    return 0;
}