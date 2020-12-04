#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Query {
    ll x, y, z;
};

struct UnionFind {
    UnionFind(int n) {
        _rank.assign(n, 0);
        _count.assign(n, 1);
        _parent.resize(n);
        for (int i = 0; i < n; ++i) {
            _parent[i] = i;
        }
    }

    int find(int x) {
        if (x == _parent[x])
            return x;
        return _parent[x] = find(_parent[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    void unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        if (_rank[x] < _rank[y]) {
            _parent[x] = y;
            _count[y] += _count[x];
        }
        else {
            _parent[y] = x;
            _count[x] += _count[y];
            if (_rank[x] == _rank[y])
                _rank[x]++;
        }
    }

    int count(int x) {
        x = find(x);
        return _count[x];
    }

    vector<int> _rank;
    vector<int> _parent;
    vector<int> _count;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<pll> edge(M);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        edge[i].first = a - 1;
        edge[i].second = b - 1;
    }
    ll Q;
    cin >> Q;
    vector<Query> q(Q);
    REP(i, Q) {
        cin >> q[i].x >> q[i].y >> q[i].z;
        q[i].x--;
        q[i].y--;
    }

    vector<pll> ans(Q, pll(0, M));
    while (true) {
        vector<vector<ll>> mid(M + 1);
        bool update = false;
        REP(i, Q) {
            ll diff = abs(ans[i].first - ans[i].second);
            if (diff <= 1)
                continue;
            ll m = (ans[i].first + ans[i].second) / 2;
            mid[m].push_back(i);
            update = true;
        }
        if (!update)
            break;

        UnionFind uf(N);
        REP(i, M) {
            uf.unit(edge[i].first, edge[i].second);
            REP(j, mid[i + 1].size()) {
                ll index = mid[i + 1][j];
                ll x = q[index].x;
                ll y = q[index].y;
                ll z = q[index].z;
                ll sum = uf.count(x) + uf.count(y);
                if (uf.same(x, y))
                    sum -= uf.count(y);
                if (z <= sum)
                    ans[index].second = i + 1;
                else
                    ans[index].first = i + 1;
            }
        }
    }

    REP(i, Q) {
        cout << ans[i].second << endl;
    }
    return 0;
}