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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    priority_queue<tuple<pll, ll>, vector<tuple<pll, ll>>, function<bool(tuple<pll, ll>, tuple<pll, ll>)>> q(
            [](tuple<pll, ll> a, tuple<pll, ll> b) {
                return get<1>(a) > get<1>(b);
            });
    REP(i, N) {
        REP(j, N) {
            ll a;
            cin >> a;
            if (a < 0)
                continue;
            q.push(make_tuple(pll(i, j), a));
        }
    }
    UnionFind uf(N);
    ll ans = 0;
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        pll p = get<0>(t);
        if (uf.same(p.first, p.second))
            continue;
        uf.unit(p.first, p.second);
        ans += get<1>(t);
    }
    cout << ans << endl;
    return 0;
}