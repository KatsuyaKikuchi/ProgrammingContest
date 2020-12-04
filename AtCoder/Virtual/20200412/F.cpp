#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[100005];

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
    ll y;
    ll index;
};

struct Data2 {
    vector<vector<ll>> X;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    vector<ll> x;
    REP(i, N) {
        x.push_back(A[i].first);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    UnionFind uf(x.size());
    vector<Data> d;
    REP(i, N) {
        ll index = lower_bound(x.begin(), x.end(), A[i].first) - x.begin();
        d.push_back(Data{A[i].second, index});
    }
    sort(d.begin(), d.end(), [](Data a, Data b) { return a.y < b.y; });
    REP(i, d.size() - 1) {
        if (d[i].y == d[i + 1].y)
            uf.unit(d[i].index, d[i + 1].index);
    }

    vector<vector<ll>> X(x.size());
    REP(i, N) {
        ll index = lower_bound(x.begin(), x.end(), A[i].first) - x.begin();
        X[index].push_back(A[i].second);
    }
    REP(i, X.size()) {
        sort(X[i].begin(), X[i].end());
        X[i].erase(unique(X[i].begin(), X[i].end()), X[i].end());
    }

    ll s = 1;
    REP(i, x.size()) {
        s = std::max(s, uf.find(i) + 1LL);
    }

    vector<Data2> d2(s);
    REP(i, X.size()) {
        d2[uf.find(i)].X.push_back(X[i]);
    }

    ll ans = 0;
    REP(i, d2.size()) {
        ll xs = d2[i].X.size();
        if (xs <= 1)
            continue;

        vector<ll> y;
        ll num = 0;
        REP(j, d2[i].X.size()) {
            num += d2[i].X[j].size();
            REP(k, d2[i].X[j].size()) {
                y.push_back(d2[i].X[j][k]);
            }
        }
        sort(y.begin(), y.end());
        y.erase(unique(y.begin(), y.end()), y.end());
        if (y.size() <= 1)
            continue;

        ans += xs * y.size() - num;
    }
    cout << ans << endl;

    return 0;
}