#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

template<typename T>
struct SegmentTree {
    using F = function<T(T, T)>;

    SegmentTree(F func, T id)
            : merge(func), identity(id) {}

    void init(ll n) {
        offset = 1;
        while (offset < n)
            offset <<= 1;
        node.assign(offset << 1, identity);
    }

    void build(const vector<T> &v) {
        int n = static_cast<int>(v.size());
        init(n);
        for (int i = 0; i < n; ++i) {
            node[offset + i] = v[i];
        }
        for (int i = offset - 1; i >= 0; --i) {
            node[i] = merge(node[(i << 1) | 0], node[(i << 1) | 1]);
        }
    }

    void set(int index, T value) {
        index += offset;
        node[index] = value;
        while (index >>= 1) {
            node[index] = merge(node[(index << 1) | 0], node[(index << 1) | 1]);
        }
    }

    //! [left, right]
    T get(int left, int right) {
        left += offset;
        right += offset + 1;

        T val = identity;
        while (left < right) {
            if (left & 1)
                val = merge(val, node[left++]);
            if (right & 1)
                val = merge(val, node[--right]);

            left >>= 1;
            right >>= 1;
        }
        return val;
    }

    T identity;
    F merge;
    vector<T> node;
    int offset;
};

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

ll solve(ifstream& rs) {
    ll N, M, A, B;
    rs >> N >> M >> A >> B;
    A--;
    B--;
    RootedTree tree(N);
    vector<ll> C(N);
    REP(i, N) {
        ll p;
        rs >> p >> C[i];
        if (p > 0)
            tree.addEdge(p - 1, i);
    }
    tree.build();

    ll p = tree.lca(A, B);
    vector<ll> v, v1;
    while (A != p) {
        v.push_back(A);
        A = tree.mVertexTbl[A].parent;
    }
    while (B != p) {
        v1.push_back(B);
        B = tree.mVertexTbl[B].parent;
    }
    v.push_back(p);
    reverse(v1.begin(), v1.end());
    REP(i, v1.size()) {
        v.push_back(v1[i]);
    }

    ll X = v.size();
    SegmentTree<ll> seg([](ll a, ll b) { return std::min(a, b); }, INF);
    seg.init(X + 5);
    seg.set(0, 0);
    vector<bool> U(N, false);
    FOR(i, X - 1, 1) {
        queue<pll> q;
        q.push(pll(v[i], 0));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            if (U[t.first])
                continue;
            U[t.first] = true;
            if (C[t.first] != 0) {
                ll s = std::max(0LL, i - M + t.second);
                ll e = i - 1;
                if (s > e)
                    continue;
                ll mn = seg.get(s, e);
                ll x = std::max(0LL, i - t.second);
                seg.set(x, std::min(seg.get(x, x), mn + C[t.first]));
            }

            ll p = tree.mVertexTbl[t.first].parent;
            if (p >= 0 && !U[p]) {
                if (p != v[i + 1])
                    q.push(pll(p, t.second + 1));
            }
            for (auto &n:tree.mVertexTbl[t.first].child) {
                if (U[n.first] || n.first == v[i + 1])
                    continue;
                q.push(pll(n.first, t.second + 1));
            }
        }
    }

    ll ret = seg.get(std::max(0LL, X - 1 - M), X - 2);
    if (ret == INF)
        return -1;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    std::string rFile = "../Facebook Hacker Cup/2020/Qualification Round/D2.txt";
    std::ifstream rs;
    rs.open(rFile, std::ios::in);

    string wFile = "../Facebook Hacker Cup/2020/Qualification Round/D2_ans.txt";
    std::ofstream ws;
    ws.open(wFile, std::ios::out);

    ll Q;
    rs >> Q;
    REP(i, Q) {
        ws << "Case #" << i + 1 << ": ";
        ws << solve(rs) << endl;
    }
    return 0;
}