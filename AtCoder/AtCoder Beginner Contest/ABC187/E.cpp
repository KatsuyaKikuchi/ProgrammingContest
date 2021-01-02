#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

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
    };

    int mRoot;
    vector<Vertex> mVertexTbl;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> e(N - 1);
    RootedTree tree(N, 0);
    REP(i, N - 1) {
        cin >> e[i].first >> e[i].second;
        e[i].first--;
        e[i].second--;
        tree.addEdge(e[i].first, e[i].second);
    }
    tree.build();

    vector<ll> C(N, 0);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll t, q, x;
        cin >> t >> q >> x;
        q--;
        if (t == 1) {
            ll a = e[q].first;
            ll b = e[q].second;
            if (tree.mVertexTbl[a].parent == b) {
                C[a] += x;
            }
            else {
                C[b] -= x;
                C[0] += x;
            }
        }
        else {
            ll b = e[q].first;
            ll a = e[q].second;
            if (tree.mVertexTbl[a].parent == b) {
                C[a] += x;
            }
            else {
                C[b] -= x;
                C[0] += x;
            }
        }
    }

    vector<ll> ans(N, 0);

    {
        queue<pll> q;
        q.push(pll(0, C[0]));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ans[t.first] = t.second;
            REP(i, tree.mVertexTbl[t.first].child.size()) {
                ll nxt = tree.mVertexTbl[t.first].child[i].first;
                ll cost = C[nxt] + t.second;
                q.push(pll(nxt, cost));
            }
        }
    }
    REP(i, N) {
        cout << ans[i] << endl;
    }

    return 0;
}