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
    }

    struct Vertex {
        vector<pair<int, long long int>> child;
        long long int depth = 0;
        int parent = -1;
        ll cost;
        ll count = 0;
    };

    int mRoot;
    vector<Vertex> mVertexTbl;
};

pll B[200005];
bool U[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    RootedTree tree(N);
    REP(i, N) {
        auto &v = tree.mVertexTbl[i];
        ll b, c;
        cin >> v.cost >> b >> c;
        if (b > c)
            B[i].first = 1;
        if (b < c)
            B[i].second = 1;
    }

    REP(i, N - 1) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        tree.addEdge(u, v);
    }
    tree.build();

    {
        memset(U, 0, sizeof(U));
        stack<pll> s;
        s.push(pll(0, INF));
        while (!s.empty()) {
            pll t = s.top();
            s.pop();
            if (tree.mVertexTbl[t.first].cost < t.second) {
                U[t.first] = true;
            }
            ll cost = std::min(tree.mVertexTbl[t.first].cost, t.second);
            for (auto &n: tree.mVertexTbl[t.first].child) {
                ll nxt = n.first;
                s.push(pll(nxt, cost));
            }
        }
    }
    ll ans = 0;
    {
        queue<ll> q;
        REP(i, N) {
            if (tree.mVertexTbl[i].child.size() == 0)
                q.push(i);
        }

        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            auto &node = tree.mVertexTbl[t];
            if (U[t]) {
                ll mn = std::min(B[t].first, B[t].second);
                ans += 2LL * mn * node.cost;
                B[t].first -= mn;
                B[t].second -= mn;
            }

            if (node.parent >= 0) {
                B[node.parent].first += B[t].first;
                B[node.parent].second += B[t].second;
                auto &parent = tree.mVertexTbl[node.parent];
                if (parent.child.size() == (++parent.count))
                    q.push(node.parent);
            }
        }
    }
    if (B[0].first != 0 || B[0].second != 0)
        ans = -1;
    cout << ans << endl;
    return 0;
}