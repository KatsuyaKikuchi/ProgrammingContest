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
        num.assign(n, 1);
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
            num[y] += num[x];
        }
        else {
            parent[y] = x;
            num[x] += num[y];
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    vector<int> rank;
    vector<int> parent;
    vector<int> num;
};

pll E[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        cin >> E[i].first >> E[i].second;
        E[i].first--;
        E[i].second--;
    }

    UnionFind uf(N);

    vector<ll> v;
    ll p = N * (N - 1) / 2;
    for (ll i = M - 1; i >= 0; --i) {
        v.push_back(p);
        if (uf.same(E[i].first, E[i].second))
            continue;

        ll x = uf.find(E[i].first);
        ll y = uf.find(E[i].second);
        p -= uf.num[x] * uf.num[y];
        uf.unit(x, y);
    }

    reverse(v.begin(), v.end());
    REP(i, v.size()) {
        cout << v[i] << endl;
    }
    return 0;
}