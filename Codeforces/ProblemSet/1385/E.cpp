#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

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

struct Vertex {
    vector<ll> node;
    ll cnt = 0;
};

void solve() {
    ll N, M;
    cin >> N >> M;
    UnionFind uf(N);
    vector<pll> E;
    vector<pll> T;
    vector<Vertex> V(N);
    vector<ll> C(N, -1);
    REP(i, M) {
        ll t, a, b;
        cin >> t >> a >> b;
        a--;
        b--;
        if (t == 0) {
            E.push_back(pll(a, b));
        }
        else {
            V[a].node.push_back(b);
            V[b].cnt++;
            uf.unit(a, b);
            T.push_back(pll(a + 1, b + 1));
        }
    }

    queue<ll> q;
    REP(i, N) {
        if (V[i].cnt == 0)
            q.push(i);
    }
    ll index = 0;
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        C[t] = index++;
        for (auto &n:V[t].node) {
            V[n].cnt--;
            if (V[n].cnt == 0)
                q.push(n);
        }
    }

    REP(i, N) {
        if (C[i] < 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (auto &p:E) {
        ll a = p.first;
        ll b = p.second;
        if (uf.same(a, b)) {
            if (C[a] > C[b])
                swap(a, b);
        }
        else {
            if (uf.find(a) > uf.find(b))
                swap(a, b);
        }
        T.push_back(pll(a + 1, b + 1));
    }

    for (auto &p:T) {
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}