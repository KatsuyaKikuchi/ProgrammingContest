#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Edge {
    ll a, b, cost;
};

struct UnionFind {
    UnionFind(int n) {
        rank.assign(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        mLink.assign(n, false);
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool link(int x) {
        x = find(x);
        return mLink[x];
    }

    void setLink(int x) {
        x = find(x);
        mLink[x] = true;
    }

    void unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        if (rank[x] < rank[y]) {
            if (link(x))
                mLink[y] = true;
            parent[x] = y;
        }
        else {
            if (link(y))
                mLink[x] = true;
            parent[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    vector<int> rank;
    vector<int> parent;
    vector<bool> mLink;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q0([](pll a, pll b) { return a.first > b.first; });
    REP(i, N) {
        ll c;
        cin >> c;
        q0.push(pll(c, i));
    }
    priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> q1([](Edge a, Edge b) { return a.cost > b.cost; });
    REP(i, M) {
        Edge e;
        cin >> e.a >> e.b >> e.cost;
        e.a--;
        e.b--;
        q1.push(e);
    }
    UnionFind uf(N);
    ll ans = 0;
    while (!q0.empty() && !q1.empty()) {
        while (!q0.empty()) {
            pll t = q0.top();
            if (!uf.link(t.second))
                break;
            q0.pop();
        }
        while (!q1.empty()) {
            Edge e = q1.top();
            if (uf.same(e.a, e.b) || (uf.link(e.a) && uf.link(e.b))) {
                q1.pop();
                continue;
            }
            break;
        }
        if (q0.empty() || q1.empty())
            break;

        auto c0 = q0.top();
        auto c1 = q1.top();
        ans += std::min(c0.first, c1.cost);
        //cout << c0.second << ":" << c0.first << " " << c1.a << "," << c1.b << ":" << c1.cost << endl;
        if (c0.first <= c1.cost) {
            uf.setLink(c0.second);
            q0.pop();
        }
        else {
            uf.unit(c1.a, c1.b);
            q1.pop();
        }
    }

    while (!q0.empty()) {
        pll t = q0.top();
        q0.pop();
        if (uf.link(t.second))
            continue;
        uf.setLink(t.second);
        ans += t.first;
    }

    cout << ans << endl;
    return 0;
}