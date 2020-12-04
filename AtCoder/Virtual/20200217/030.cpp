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
        mVertexTbl[b].child.push_back(pair<int, long long int>(b, cost));
    }

    void build() {
        queue<tuple<int, int, long long int>> q;
        q.push(make_tuple(mRoot, -1, 0));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int index = get<0>(t);
            int parent = get<1>(t);
            long long int cost = get<2>(t);
            mVertexTbl[index].parent = parent;
            mVertexTbl[index].depth = cost;
            for (auto it = mVertexTbl[index].child.begin(); it != mVertexTbl[index].child.end();) {
                int nxt = (*it).first;
                if (nxt == parent) {
                    mVertexTbl[index].child.erase(it);
                    continue;
                }
                q.push(make_tuple(nxt, index, cost + (*it).second));
                ++it;
            }
        }
    }

    vector<int> getLeaf() {
        vector<int> leafs;
        for (int i = 0; i < mVertexTbl.size(); ++i) {
            if (mVertexTbl[i].child.size() == 0)
                leafs.push_back(i);
        }
        return leafs;
    }

    struct Vertex {
        vector<pair<int, long long int>> child;
        long long int depth = 0;
        int parent = -1;
    };

    int mRoot;
    vector<Vertex> mVertexTbl;
};

ll C[100005][2];
ll S[100005];

int main() {
    ll N;
    cin >> N;
    RootedTree tree(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        tree.addEdge(a, b);
    }

    tree.build();
    memset(C, 0, sizeof(C));
    memset(S, 0, sizeof(S));
    auto leafs = tree.getLeaf();
    queue<ll> q;
    REP(i, leafs.size()) {
        ll index = leafs[i];
        q.push(index);
    }

    while (!q.empty()) {
        ll node = q.front();
        q.pop();
        {
            //! 白
            ll white = 1;
            REP(i, tree.mVertexTbl[node].child.size()) {
                ll c = tree.getChild(node, i);
                white = (white * (C[c][0] + C[c][1])) % MOD;
            }
            C[node][0] = white;
        }
        {
            //! 黒
            ll black = 1;
            REP(i, tree.mVertexTbl[node].child.size()) {
                ll c = tree.getChild(node, i);
                black = (black * C[c][0]) % MOD;
            }
            C[node][1] = black;
        }
        ll par = tree.getParent(node);
        if (par >= 0) {
            S[par]++;
            if (S[par] == tree.mVertexTbl[par].child.size())
                q.push(par);
        }
    }

    cout << (C[0][0] + C[0][1]) % MOD << endl;

    return 0;
}