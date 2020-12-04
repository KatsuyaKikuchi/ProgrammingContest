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
            mOffset <<= 1;
        mDat.assign(mOffset << 1, pair<int, int>(INF_VALUE, -1));
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
                : mN(0), mPow(0) {}

        BinaryIndexTree(int n)
                : mN(n) {
            mPow = 1;
            while (mPow < n)
                mPow <<= 1;
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
        long long int mPow;
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    EulerTree tree(N);
    REP(i, N - 1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        tree.addEdge(a, b, i, c);
    }
    tree.build();
    ll Q, K;
    cin >> Q >> K;
    K--;
    REP(_, Q) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << tree.cost(x, K) + tree.cost(K, y) << endl;
    }

    return 0;
}