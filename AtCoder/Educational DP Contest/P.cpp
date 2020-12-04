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
        ll count = 0;
    };

    int mRoot;
    vector<Vertex> mVertexTbl;
};

ll dp[100005][3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
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
    queue<ll> q;
    REP(i, N) {
        dp[i][0] = dp[i][1] = 1;
        if (tree.mVertexTbl[i].child.size() == 0)
            q.push(i);
    }

    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        for (auto &v:tree.mVertexTbl[t].child) {
            dp[t][0] *= (dp[v.first][0] + dp[v.first][1]);
            dp[t][0] %= MOD;
            dp[t][1] *= dp[v.first][0];
            dp[t][1] %= MOD;
        }
        ll p = tree.mVertexTbl[t].parent;
        if (p >= 0) {
            if (++tree.mVertexTbl[p].count == tree.mVertexTbl[p].child.size())
                q.push(p);
        }
    }

    cout << (dp[0][0] + dp[0][1]) % MOD << endl;
    return 0;
}