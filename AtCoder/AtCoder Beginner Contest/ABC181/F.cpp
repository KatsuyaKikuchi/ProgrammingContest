#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<double, ll> pdl;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
pll A[105];

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

double len(pll a, pll b) {
    double x = a.first - b.first;
    double y = a.second - b.second;
    return sqrt(x * x + y * y);
}

bool check(double r) {
    UnionFind uf(N + 2);

    REP(i, N) {
        FOR(j, N, i + 1) {
            if (len(A[i], A[j]) < 2 * r)
                uf.unit(i, j);
        }
    }

    REP(i, N) {
        if (100 - A[i].second < 2 * r)
            uf.unit(N, i);
        if (A[i].second + 100 < 2 * r)
            uf.unit(N + 1, i);
    }

    return !uf.same(N, N + 1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    double ok = 0, ng = 101;
    REP(_, 100) {
        double mid = (ok + ng) * 0.5;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }

    cout << OF64 << ok << endl;
}