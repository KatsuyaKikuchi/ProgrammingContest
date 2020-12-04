#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll E[200005];

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
    ll N, M;
    cin >> N >> M;
    vector<pll> v;
    REP(i, M) {
        cin >> E[i].first >> E[i].second;
        E[i].first--;
        E[i].second--;
        ll a = E[i].first, b = E[i].second;
        v.push_back(pll(a, a));
        v.push_back(pll(b, b));
        v.push_back(pll(a, b));
        v.push_back(pll(b, a));
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    UnionFind uf(v.size());
    REP(i, M) {
        ll a = E[i].first, b = E[i].second;
        {
            ll i0 = lower_bound(v.begin(), v.end(), pll(a, a)) - v.begin();
            ll i1 = lower_bound(v.begin(), v.end(), pll(b, b)) - v.begin();
            uf.unit(i0, i1);
        }
        {
            ll i0 = lower_bound(v.begin(), v.end(), pll(a, b)) - v.begin();
            ll i1 = lower_bound(v.begin(), v.end(), pll(b, a)) - v.begin();
            uf.unit(i0, i1);
        }
    }
    vector<ll> t;
    REP(i, v.size()) {
        t.push_back(uf.find(i));
    }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    ll ans = N * N - v.size() + t.size();

    cout << ans << endl;
    return 0;
}