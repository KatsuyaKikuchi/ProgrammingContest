#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<vector<pll>> V;
struct Query {
    ll x, y, z;
};

struct UnionFind {
    UnionFind(int n) {
        rank.assign(n, 0);
        parent.resize(n);
        counts.assign(n, 1);
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
            counts[y] += counts[x];
        }
        else {
            parent[y] = x;
            counts[x] += counts[y];
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    int count(int x) {
        x = find(x);
        return counts[x];
    }

    vector<int> rank;
    vector<int> parent;
    vector<int> counts;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<pll> edge(M);
    REP(i, M) {
        cin >> edge[i].first >> edge[i].second;
        edge[i].first--;
        edge[i].second--;
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
        vector<vector<ll>> mids(M + 1);
        ll e = false;
        REP(i, Q) {
            if (abs(ans[i].first - ans[i].second) <= 1)
                continue;
            ll mid = (ans[i].first + ans[i].second) / 2;
            mids[mid].push_back(i);
            e = true;
        }
        if (!e)
            break;

        UnionFind uf(N);
        REP(i, M) {
            uf.unit(edge[i].first, edge[i].second);
            REP(j, mids[i + 1].size()) {
                ll idx = mids[i + 1][j];
                ll x = q[idx].x;
                ll y = q[idx].y;

                ll count = uf.count(x);
                if (!uf.same(x, y))
                    count += uf.count(y);
                if (count >= q[idx].z)
                    ans[idx].second = i + 1;
                else
                    ans[idx].first = i + 1;
            }
        }
    }

    REP(i, Q) {
        cout << ans[i].second << endl;
    }

    return 0;
}