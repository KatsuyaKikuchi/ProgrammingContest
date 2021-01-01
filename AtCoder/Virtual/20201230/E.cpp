#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

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
    REP(i, N) {
        cin >> A[i];
    }
    RootedTree tree(N);
    REP(_, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        tree.addEdge(a, b);
    }

    if (N == 2) {
        if (A[0] == A[1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return 0;
    }

    queue<ll> q;
    REP(i, N) {
        if (tree.mVertexTbl[i].child.size() > 1) {
            tree.mRoot = i;
        }
        else {
            q.push(i);
        }
    }
    tree.build();

    vector<ll> count(N, 0);
    while (!q.empty()) {
        ll idx = q.front();
        q.pop();
        ll sum = 0;
        vector<ll> v;
        REP(i, tree.mVertexTbl[idx].child.size()) {
            ll child = tree.mVertexTbl[idx].child[i].first;
            sum += A[child];
            v.push_back(A[child]);
        }
        ll parent = tree.mVertexTbl[idx].parent;
        if (parent >= 0) {
            count[parent]++;
            if (count[parent] == tree.mVertexTbl[parent].child.size()) {
                q.push(parent);
            }
        }
        if (tree.mVertexTbl[idx].child.size() == 0) {
            continue;
        }
        if (sum < A[idx]) {
            cout << "NO" << endl;
            return 0;
        }
        sort(v.begin(), v.end());
        ll diff = sum - A[idx];
        A[idx] -= diff;
        REP(i, v.size() - 1) {
            ll d = std::min({diff, v[i], sum / 2});
            diff -= d;
            sum -= 2 * d;
        }
        if (diff > 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    ll root = tree.mRoot;
    if (A[root] != 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}