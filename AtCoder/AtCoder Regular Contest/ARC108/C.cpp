#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<pll> edge;
};
struct Edge {
    ll a;
    ll b;
    ll c;
};

Edge E[200005];
Vertex V[100005];

struct UnionFind {
    UnionFind(int n) {
        rank.assign(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    void unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        if (rank[x] < rank[y]) {
            parent[x] = y;
        }
        else {
            parent[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    vector<int> rank;
    vector<int> parent;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        E[i].a = a;
        E[i].b = b;
        E[i].c = c;
    }

    vector<ll> ans(N + 5, 0);
    UnionFind uf(N + 5);
    REP(i, M) {
        ll a = E[i].a, b = E[i].b;
        if (uf.same(a, b))
            continue;
        ll c = E[i].c;
        uf.unit(a, b);
        V[a].edge.push_back(pll(b, c));
        V[b].edge.push_back(pll(a, c));
    }

    queue<pll> q;
    vector<bool> used(N + 5, false);
    q.push(pll(0, -1));
    used[0] = true;

    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        if (ans[t.first] == 0) {
            REP(i, V[t.first].edge.size()) {
                ll n = V[t.first].edge[i].second;
                if (used[n])
                    continue;
                ll c = V[t.first].edge[i].second;
                if (c != t.second) {
                    ans[t.first] = c;
                    break;
                }
            }
            if (ans[t.first] == 0)
                ans[t.first] = 1;
            if (ans[t.first] == t.second)
                ans[t.first] = 2;
        }

        REP(i, V[t.first].edge.size()) {
            ll n = V[t.first].edge[i].first;
            ll c = V[t.first].edge[i].second;
            if (used[n])
                continue;
            if (c != ans[t.first]) {
                ans[n] = c;
            }
            q.push(pll(n, ans[t.first]));
            used[n] = true;
        }
    }


    REP(i, N) {
        cout << ans[i] << endl;
    }

    return 0;
}