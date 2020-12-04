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

bool U[100005];

int main() {
    ll N, M;
    cin >> N >> M;
    UnionFind uf(N);

    REP(i, M) {
        ll x, y, z;
        cin >> x >> y >> z;
        uf.unit(x - 1, y - 1);
    }
    memset(U, 0, sizeof(U));
    ll ans = 0;
    REP(i, N) {
        ll p = uf.find(i);
        if (U[p])
            continue;
        U[p] = true;
        ans++;
    }
    cout << ans << endl;
    return 0;
}