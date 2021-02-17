#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

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

    vector<int> topological_sort() {
        vector<int> ret;
        queue<int> q;
        for (int i = 0; i < mVertexTbl.size(); ++i) {
            if (mVertexTbl[i].child.size() == 0)
                q.push(i);
        }
        vector<int> count(mVertexTbl.size(), 0);
        while (!q.empty()) {
            ll idx = q.front();
            q.pop();
            ret.push_back(idx);
            int parent = mVertexTbl[idx].parent;
            if (parent < 0)
                continue;
            if (++count[parent] == mVertexTbl[parent].child.size()) {
                q.push(parent);
            }
        }
        return ret;
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
    RootedTree tree(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        tree.addEdge(a, b);
    }
    tree.build();
    ll K;
    cin >> K;
    vector<ll> ans(N, INF);
    REP(i, K) {
        ll v, p;
        cin >> v >> p;
        v--;
        ans[v] = p;
    }

    ll even = 0;
    REP(i, N) {
        if (ans[i] == INF)
            continue;
        if (ans[i] % 2 == 0) {
            even = tree.mVertexTbl[i].depth % 2;
            break;
        }
    }

    REP(i, N) {
        if (ans[i] == INF)
            continue;
        if (ans[i] % 2 == 0) {
            if (tree.mVertexTbl[i].depth % 2 != even) {
                cout << "No" << endl;
                return 0;
            }
        }
        else {
            if (tree.mVertexTbl[i].depth % 2 != (even + 1) % 2) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    vector<pll> range(N, pll(-INF, INF));
    auto vtx = tree.topological_sort();
    for (auto &t : vtx) {
        if (ans[t] != INF) {
            range[t].first = std::max(ans[t], range[t].first);
            range[t].second = std::min(ans[t], range[t].second);
        }
        for (auto &child: tree.mVertexTbl[t].child) {
            ll idx = child.first;
            range[t].first = std::max(range[t].first, range[idx].first - 1);
            range[t].second = std::min(range[t].second, range[idx].second + 1);
        }
        if (range[t].first > range[t].second) {
            cout << "No" << endl;
            return 0;
        }
    }

    queue<ll> q;
    q.push(0);
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        if (range[t].first > range[t].second) {
            cout << "No" << endl;
            return 0;
        }

        for (int x = range[t].first; x <= range[t].second; ++x) {
            if (tree.mVertexTbl[t].depth % 2 == even) {
                if (x % 2 == 0) {
                    ans[t] = x;
                    break;
                }
            }
            else {
                if (x % 2 == 1) {
                    ans[t] = x;
                    break;
                }
            }
        }
        if (ans[t] != INF) {
            range[t].first = std::max(ans[t], range[t].first);
            range[t].second = std::min(ans[t], range[t].second);
        }
        else {
            cout << "No" << endl;
            return 0;
        }

        for (auto &child: tree.mVertexTbl[t].child) {
            ll idx = child.first;
            range[idx].first = std::max(range[t].first - 1, range[idx].first);
            range[idx].second = std::min(range[t].second + 1, range[idx].second);
            q.push(idx);
        }
    }

    cout << "Yes" << endl;
    REP(i, N) {
        //cout << range[i].first << " " << range[i].second << endl;
        cout << ans[i] << endl;
    }
    return 0;
}