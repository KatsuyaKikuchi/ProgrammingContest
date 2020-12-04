#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

//! UnionFind with History
class UnionFindEx {
public:
    explicit UnionFindEx(int n) :
            mSize(n) {
        mNodeTbl.clear();
        for (int i = 0; i < n; ++i) {
            mNodeTbl.emplace_back(i);
        }
    }

    int find(int x) {
        if (mNodeTbl[x].parent == x)
            return x;
        return mNodeTbl[x].parent = find(mNodeTbl[x].parent);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    void unit(int x, int y) {
        x = find(x);
        y = find(y);
        Node newNode = Node(static_cast<int>(mNodeTbl.size()));
        if (x != y) {
            newNode.children.push_back(x);
            newNode.children.push_back(y);
            mNodeTbl[x].parent = mNodeTbl[y].parent = newNode.parent;
        }
        mNodeTbl.push_back(newNode);
    }

    void build() {
        for (int i = static_cast<int>(mNodeTbl.size()) - 1; i >= 0; --i) {
            if (mNodeTbl[i].depth >= 0)
                continue;
            dfs(i);
        }

        for (int d = 1; d < COUNT; ++d) {
            for (auto &node:mNodeTbl) {
                int nxt = node.doubling[d - 1];
                if (nxt < 0)
                    continue;
                node.doubling[d] = mNodeTbl[nxt].doubling[d - 1];
            }
        }
    }

    int history(int x, int y) {
        if (!same(x, y))
            return -1;
        return lca(x, y) - mSize;
    }

private:
    void dfs(int index, int depth = 0) {
        mNodeTbl[index].depth = depth;
        for (auto &child:mNodeTbl[index].children) {
            dfs(child, depth + 1);
            mNodeTbl[child].doubling[0] = index;
        }
    }

    int lca(int x, int y) {
        if (mNodeTbl[x].depth > mNodeTbl[y].depth)
            swap(x, y);
        ll diff = mNodeTbl[y].depth - mNodeTbl[x].depth;
        for (int i = 0; i < COUNT; ++i) {
            if ((diff >> i) & 1)
                y = mNodeTbl[y].doubling[i];
        }

        if (x == y)
            return x;

        for (int i = COUNT - 1; i >= 0; --i) {
            if (mNodeTbl[x].doubling[i] == mNodeTbl[y].doubling[i])
                continue;
            x = mNodeTbl[x].doubling[i];
            y = mNodeTbl[y].doubling[i];
        }
        return mNodeTbl[x].doubling[0];
    }

    struct Node {
        explicit Node(int parent) :
                parent(parent),
                depth(-1) {
            doubling.assign(COUNT, -1);
        }

        int parent;
        int depth;
        vector<int> children;
        vector<int> doubling;
    };

    vector<Node> mNodeTbl;
    int mSize;
    static const int COUNT = 50;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    UnionFindEx uf(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        uf.unit(a - 1, b - 1);
    }

    uf.build();
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll x, y;
        cin >> x >> y;
        ll ret = uf.history(x - 1, y - 1);
        if (ret >= 0)
            ret++;
        cout << ret << endl;
    }
    return 0;
}