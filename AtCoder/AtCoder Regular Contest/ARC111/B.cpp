#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include <vector>
#include <utility>

//===
struct UnionFind {
    std::vector<int> parent;

    UnionFind() = default;

    UnionFind(int nmemb) {
        init(nmemb);
    };

    void init(int nmemb) {
        parent.clear();
        parent.resize(nmemb, -1);
    };

    int root(int x) {
        if (parent[x] < 0)
            return x;
        return parent[x] = root(parent[x]);
    };

    void unite(int x, int y) {
        x = root(x);
        y = root(y);

        if (x == y)
            return;

        if (parent[y] < parent[x])
            std::swap(x, y);

        parent[x] += parent[y];
        parent[y] = x;

        return;
    };

    bool same(int x, int y) {
        return root(x) == root(y);
    };

    int size(int x) {
        return -(parent[root(x)]);
    };
};
//===

#endif

#include <iostream>
#include <queue>

using namespace std;
using i64 = long long;

int main() {
    i64 n, m;
    cin >> m;
    n = 400005;
    UnionFind uf(n);

    vector<i64> v(n);
    vector<i64> x(m);
    vector<i64> y(m);
    for (int i = 0; i < n; ++i) {
        v[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;

        uf.unite(x[i], y[i]);
    }

    vector<priority_queue<i64>> p_que(n);
    for (int i = 0; i < n; i++) {
        p_que[uf.root(i)].push(v[i]);
    }

    i64 ans = 0;
    for (int i = 0; i < m; i++) {
        if (p_que[uf.root(x[i])].empty())
            continue;
        ans += p_que[uf.root(x[i])].top();
        p_que[uf.root(x[i])].pop();
    }

    cout << ans << endl;
    return 0;
}
