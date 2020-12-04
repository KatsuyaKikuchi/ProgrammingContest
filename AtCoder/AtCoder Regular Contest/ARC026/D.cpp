#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Edge {
    ll a, b;
    ll c;
    ll t;
};

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

ll N, M;
vector<Edge> v;

bool check(double X) {
    UnionFind uf(N);
    double C = 0, T = 0;
    priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> q(
            [X](Edge a, Edge b) { return a.t * X - a.c < b.t * X - b.c; });

    REP(i, M) {
        auto e = v[i];
        if (e.t * X - e.c >= 0) {
            uf.unit(e.a, e.b);
            C += e.c;
            T += e.t;
            continue;
        }
        q.push(e);
    }

    while (!q.empty()) {
        auto e = q.top();
        q.pop();
        if (uf.same(e.a, e.b))
            continue;
        uf.unit(e.a, e.b);
        C += e.c;
        T += e.t;
    }
    return C <= X * T;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    v.resize(M);
    REP(i, M) {
        cin >> v[i].a >> v[i].b >> v[i].c >> v[i].t;
    }

    double ans = INF, ng = 0;
    REP(_, 200) {
        double mid = (ans + ng) * 0.5;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }
    cout << OF64 << ans << endl;

    return 0;
}