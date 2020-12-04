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

        dfs(mRoot);
        mVertexTbl[mRoot].value = 0;
        solve(mRoot);
    }

    void dfs(int index) {
        int value = 0;
        for (int i = 0; i < mVertexTbl[index].child.size(); ++i) {
            int nxt = mVertexTbl[index].child[i].first;
            dfs(nxt);
            value += std::max(0, mVertexTbl[nxt].value);
        }
        mVertexTbl[index].value = value + mVertexTbl[index].base;
    }

    void solve(int index) {
        int value = std::max(0, mVertexTbl[index].value) + mVertexTbl[index].base;
        vector<int> dp(mVertexTbl[index].child.size() + 1, 0);
        for (int i = 0; i < mVertexTbl[index].child.size(); ++i) {
            int nxt = mVertexTbl[index].child[i].first;
            mVertexTbl[index].value += std::max(0, mVertexTbl[nxt].value);
            dp[i + 1] = dp[i] + std::max(0, mVertexTbl[nxt].value);
        }

        mVertexTbl[index].value += mVertexTbl[index].base;
        for (int i = mVertexTbl[index].child.size() - 1; i >= 0; --i) {
            int nxt = mVertexTbl[index].child[i].first;

            int childValue = mVertexTbl[nxt].value;
            mVertexTbl[nxt].value = std::max(0, value + dp[i]);
            solve(nxt);
            value += std::max(0, childValue);
        }
    }

    struct Vertex {
        vector<pair<int, long long int>> child;
        long long int depth = 0;
        int parent = -1;
        int value = 0;
        int base = 0;
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
        int c;
        cin >> c;
        tree.mVertexTbl[i].base = -1 + 2 * c;
    }
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        tree.addEdge(a - 1, b - 1);
    }
    tree.build();

    REP(i, N) {
        cout << tree.mVertexTbl[i].value << " ";
    }
    cout << endl;
    return 0;
}