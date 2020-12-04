#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 14;

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

pll Query(vector<ll> &v) {
    cout << "? " << v.size();
    REP(i, v.size()) {
        cout << " " << v[i] + 1;
    }
    cout << endl;

    pll ret;
    cin >> ret.first >> ret.second;
    ret.first--;
    return ret;
}

bool Answer(pll t) {
    cout << "! " << t.first + 1 << " " << t.second + 1 << endl;
    string s;
    cin >> s;
    return s == "Correct";
}

pll getEdge(RootedTree &tree, vector<ll> &Cost) {
    ll base = tree.mRoot;
    queue<ll> q;
    q.push(base);
    vector<ll> ans;
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        ll count = 0;
        for (auto &n: tree.mVertexTbl[t].child) {
            if (Cost[n.first] != Cost[base])
                continue;
            count++;
            q.push(n.first);
        }

        if (count == 0)
            ans.push_back(t);
    }
    pll p(base, base);
    if (ans.size() > 0)
        p.first = ans[0];
    if (ans.size() > 1)
        p.second = ans[1];
    return p;
}

void solve() {
    ll N;
    cin >> N;
    RootedTree tree(N);
    vector<ll> Cost(N, INF);

    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        tree.addEdge(a, b);
    }
    ll base = 0;
    ll cnt = MAX - 1;
    {
        vector<ll> v;
        REP(i, N) {
            v.push_back(i);
        }
        pll ret = Query(v);
        base = ret.first;
        Cost[base] = ret.second;
    }
    tree.mRoot = base;
    tree.build();

    REP(_, cnt) {
        vector<ll> v;
        pll edge = getEdge(tree, Cost);
        ll len =
                std::max(1LL,
                         (Cost[base] - tree.mVertexTbl[edge.first].depth - tree.mVertexTbl[edge.second].depth) / 2);
        {
            queue<ll> q;
            q.push(edge.first);
            while (!q.empty()) {
                ll t = q.front();
                q.pop();
                ll count = 0;
                for (auto &n:tree.mVertexTbl[t].child) {
                    if (Cost[n.first] != INF)
                        continue;
                    count++;
                    q.push(n.first);
                }
                ll depth = tree.mVertexTbl[t].depth - tree.mVertexTbl[edge.first].depth;
                if ((count == 0 || depth == len) && t != edge.first)
                    v.push_back(t);
            }
        }
        {
            queue<ll> q;
            q.push(edge.second);
            while (!q.empty()) {
                ll t = q.front();
                q.pop();
                ll count = 0;
                for (auto &n:tree.mVertexTbl[t].child) {
                    if (Cost[n.first] != INF)
                        continue;
                    count++;
                    q.push(n.first);
                }

                ll depth = tree.mVertexTbl[t].depth - tree.mVertexTbl[edge.second].depth;
                if ((count == 0 || depth == len) && t != edge.second)
                    v.push_back(t);
            }
        }

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if (v.size() == 0)
            break;
        pll ret = Query(v);

        if (ret.second > Cost[base]) {
            queue<ll> q;
            REP(i, v.size()) {
                q.push(v[i]);
            }
            while (!q.empty()) {
                ll t = q.front();
                q.pop();
                Cost[t] = ret.second;
                for (auto &n: tree.mVertexTbl[t].child) {
                    q.push(n.first);
                }
            }
            continue;
        }
        ll node = ret.first;
        while (node >= 0) {
            Cost[node] = ret.second;
            node = tree.mVertexTbl[node].parent;
        }
    }
    Answer(getEdge(tree, Cost));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        solve();
    }
    return 0;
}