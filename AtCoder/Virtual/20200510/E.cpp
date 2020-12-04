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

ll CA[100005];
ll CT[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, T, A;
    cin >> N >> T >> A;
    T--;
    A--;
    RootedTree tree(N, A);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        tree.addEdge(a, b);
    }
    tree.build();
    REP(i, N) {
        CA[i] = CT[i] = INF;
    }

    {
        queue<pll> q;
        q.push(pll(A, 0));
        CA[A] = 0;
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            REP(i, tree.mVertexTbl[t.first].child.size()) {
                ll n = tree.mVertexTbl[t.first].child[i].first;
                if (CA[n] <= t.second + 1)
                    continue;
                CA[n] = t.second + 1;
                q.push(pll(n, CA[n]));
            }
        }
    }
    {
        queue<pll> q;
        q.push(pll(T, 0));
        CT[T] = 0;
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            ll n = tree.mVertexTbl[t.first].parent;
            if (CT[n] <= cost)
                continue;
            if (CA[n] <= cost)
                continue;
            CT[n] = cost;
            q.push(pll(n, cost));
        }
    }

    ll ta = T;
    REP(i, N) {
        if (CT[i] == INF)
            continue;
        if (CT[ta] < CT[i])
            ta = i;
    }
    ll ans = CT[ta];
    {
        queue<pll> q;
        q.push(pll(ta, CT[ta]));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            ans = std::max(t.second, ans);
            REP(i, tree.mVertexTbl[t.first].child.size()) {
                ll n = tree.mVertexTbl[t.first].child[i].first;
                if (CA[n] >= cost)
                    ans = std::max(ans, std::min(CA[n], cost));
                if (CA[n] > cost)
                    q.push(pll(n, cost));
            }
            ll p = tree.mVertexTbl[t.first].parent;
            if (CA[p] >= cost)
                ans = std::max(ans, std::min(CA[p], cost));
            if (CA[p] > cost)
                q.push(pll(p, cost));
        }
    }
    cout << ans << endl;
    return 0;
}