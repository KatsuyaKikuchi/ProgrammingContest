#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct EulerTree {
    EulerTree(int n) {
        mId.resize(n);
        mEdgeIndex.resize((n - 1) * 2);
        mBit = BinaryIndexTree((n - 1) * 2 + 1);
        mCost.assign(n - 1, 0);
        mVertex.resize(n);
    }

    //! add edge
    void addEdge(int u, int v, int index, long long int cost = 1) {
        mVertex[u].node.push_back(Edge{v, cost, index});
        mVertex[v].node.push_back(Edge{u, cost, index});
        mCost[index] = cost;
    }

    //! build euler tour tree
    void build(int root = 0) {
        mEulerTour.clear();
        dfs(root, -1, 0);

        mOffset = 1;
        while (mOffset < mEulerTour.size())
            mOffset <<= 1U;
        mDat.assign(mOffset << 1U, pair<int, int>(INF_VALUE, -1));
        for (int i = 0; i < mEulerTour.size(); ++i) {
            mDat[i + mOffset] = mEulerTour[i];
        }
        for (int i = mOffset - 1; i >= 0; --i) {
            mDat[i] = merge(mDat[(i << 1) | 0], mDat[(i << 1) | 1]);
        }
    }

    //! update edge cost
    void update(int index, long long int cost) {
        long long int c = mCost[index];
        mBit.add(mEdgeIndex[index * 2 + 0], cost - c);
        mBit.add(mEdgeIndex[index * 2 + 1], -cost + c);
        mCost[index] = cost;
    }

    int lca(int u, int v) {
        auto q = query(std::min(mId[u], mId[v]), std::max(mId[u], mId[v]));
        return q.second;
    }

    //! get u-v path cost
    long long int cost(int u, int v) {
        int p = lca(u, v);
        return mBit.sum(mId[u]) + mBit.sum(mId[v]) - mBit.sum(mId[p]) * 2LL;
    }

    void dfs(int vertex, int parent, int depth) {
        mId[vertex] = mEulerTour.size();
        mEulerTour.push_back(pair<int, int>(depth, vertex));
        for (int i = 0; i < static_cast<int>(mVertex[vertex].node.size()); ++i) {
            const Edge &e = mVertex[vertex].node[i];
            if (e.to == parent)
                continue;

            int go = mEulerTour.size();
            mBit.add(go, e.cost);
            mEdgeIndex[e.index * 2 + 0] = go;

            dfs(e.to, vertex, depth + 1);

            mEulerTour.push_back(pair<int, int>(depth, vertex));

            int back = mEulerTour.size();
            mBit.add(back, -e.cost);
            mEdgeIndex[e.index * 2 + 1] = back;
        }
    }

    //! [left,right]
    pair<int, int> query(int left, int right) {
        left += mOffset;
        right += mOffset + 1;

        pair<int, int> val = pair<int, int>(INF_VALUE, -1);
        while (left < right) {
            if (left & 1)
                val = merge(val, mDat[left++]);
            if (right & 1)
                val = merge(val, mDat[--right]);

            left >>= 1;
            right >>= 1;
        }
        return val;
    }

    const pair<int, int> &merge(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first < b.first)
            return a;
        return b;
    }

    struct Edge {
        int to;
        long long int cost;
        int index;
    };

    struct Vertex {
        vector<Edge> node;
    };

    struct BinaryIndexTree {
        BinaryIndexTree()
                : mN(0) {}

        BinaryIndexTree(int n)
                : mN(n) {
            node.resize(n + 1);
            REP(i, n + 1) {
                node[i] = 0;
            }
        }

        ~BinaryIndexTree() {
            node.resize(0);
        }

        //! 1-index get
        ll sum(int index) {
            ll sum = 0;
            for (int i = index; i > 0; i -= i & (-i))
                sum += node[i];
            return sum;
        }

        //! 1-index add
        void add(int index, long long int value) {
            for (int i = index; i <= mN; i += i & (-i))
                node[i] += value;
        }

        vector<long long int> node;
        int mN;
    };

    int mRoot = 0;
    vector<int> mId;
    vector<pair<int, int>> mEulerTour;   //!< (depth, index)
    BinaryIndexTree mBit;
    vector<Vertex> mVertex;
    vector<int> mEdgeIndex;
    vector<long long int> mCost;
    vector<pair<int, int>> mDat;
    int INF_VALUE = 1e8;
    int mOffset;
};

ll A[100005];

struct Query {
    ll index;
    ll cost;
    ll u, v;
};
struct Edge {
    ll index;
    ll cost;
};
vector<Query> query[100005];
vector<Edge> edge[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, Q;
    cin >> N >> Q;

    EulerTree tree0(N), tree1(N);
    REP(i, N - 1) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        edge[c].push_back(Edge{i, d});
        tree0.addEdge(a, b, i, d);
        tree1.addEdge(a, b, i, 0);
    }

    tree0.build();
    tree1.build();

    REP(i, Q) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        c--;
        d--;
        query[a].push_back(Query{i, b, c, d});
    }

    REP(i, N) {
        if (query[i].size() == 0)
            continue;

        REP(j, edge[i].size()) {
            Edge &e = edge[i][j];
            tree0.update(e.index, 0);
            tree1.update(e.index, 1);
        }

        REP(j, query[i].size()) {
            Query &q = query[i][j];
            A[q.index] = tree0.cost(q.u, q.v) + tree1.cost(q.u, q.v) * q.cost;
        }

        REP(j, edge[i].size()) {
            Edge &e = edge[i][j];
            tree0.update(e.index, e.cost);
            tree1.update(e.index, 0);
        }
    }

    REP(i, Q) {
        cout << A[i] << endl;
    }

    return 0;
}