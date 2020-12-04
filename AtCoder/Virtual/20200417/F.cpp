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

pll A[100005];

struct Data {
    ll x = 0;
    ll n = 0;
    vector<ll> y;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> X, Y;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        X.push_back(A[i].first);
        Y.push_back(A[i].second);
    }

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    vector<vector<ll>> x(X.size());
    REP(i, N) {
        ll index = lower_bound(X.begin(), X.end(), A[i].first) - X.begin();
        x[index].push_back(A[i].second);
    }
    UnionFind uf(Y.size());
    REP(i, x.size()) {
        REP(j, x[i].size() - 1) {
            ll i0 = lower_bound(Y.begin(), Y.end(), x[i][j]) - Y.begin();
            ll i1 = lower_bound(Y.begin(), Y.end(), x[i][j + 1]) - Y.begin();
            uf.unit(i0, i1);
        }
    }

    vector<Data> y(Y.size());

    REP(i, x.size()) {
        ll p = uf.find(lower_bound(Y.begin(), Y.end(), x[i][0]) - Y.begin());
        y[p].x++;
        y[p].n += x[i].size();
        REP(j, x[i].size()) {
            y[p].y.push_back(x[i][j]);
        }
    }

    ll ans = 0;
    REP(i, y.size()) {
        sort(y[i].y.begin(), y[i].y.end());
        y[i].y.erase(unique(y[i].y.begin(), y[i].y.end()), y[i].y.end());
        ans += (y[i].x * y[i].y.size() - y[i].n);
    }

    cout << ans << endl;

    return 0;
}