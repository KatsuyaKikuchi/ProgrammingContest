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

struct Data {
    ll a, b, c;
};

Data A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    UnionFind uf(N);

    REP(i, N) {
        cin >> A[i].a >> A[i].b;
        A[i].c = i;
    }

    priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) { return a.c > b.c; });
    sort(A, A + N, [](Data a, Data b) { return a.a < b.a; });
    REP(i, N - 1) {
        q.push(Data{A[i].c, A[i + 1].c, abs(A[i].a - A[i + 1].a)});
    }
    sort(A, A + N, [](Data a, Data b) { return a.b < b.b; });
    REP(i, N - 1) {
        q.push(Data{A[i].c, A[i + 1].c, abs(A[i].b - A[i + 1].b)});
    }

    ll ans = 0;
    while (!q.empty()) {
        auto d = q.top();
        q.pop();
        if (uf.same(d.a, d.b))
            continue;
        uf.unit(d.a, d.b);
        ans += d.c;
    }

    cout << ans << endl;
    return 0;
}