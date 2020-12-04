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
    };

    int mRoot;
    vector<Vertex> mVertexTbl;
};

ll C[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X;
    cin >> N >> X;
    RootedTree tree(N);
    REP(i, N - 1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        tree.addEdge(a, b, c);
    }
    tree.build();
    std::map<ll, ll> M;
    {
        queue<pll> q;
        q.push(pll(0, 0));
        C[0] = 0;
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            M[t.second]++;
            for (auto &n: tree.mVertexTbl[t.first].child) {
                ll nxt = n.first;
                ll cost = t.second ^n.second;
                C[nxt] = cost;
                q.push(pll(nxt, cost));
            }
        }
    }

    ll ans = 0;
    {
        queue<ll> q;
        q.push(0);
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            M[C[t]]--;
            ans += M[X ^ C[t]];
            for (auto &n:tree.mVertexTbl[t].child) {
                q.push(n.first);
            }
        }
    }
    cout << ans << endl;

    return 0;
}