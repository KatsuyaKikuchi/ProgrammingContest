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
    ll N;
    cin >> N;
    vector<tuple<ll, ll, ll>> v(N);
    REP(i, N) {
        ll x, y;
        cin >> x >> y;
        auto t = make_tuple(x, y, i);
        v[i] = t;
    }

    sort(v.begin(), v.end(), [](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) { return get<0>(a) < get<0>(b); });

    vector<tuple<ll, ll, ll>> e;
    REP(i, N - 1) {
        ll c = abs(get<0>(v[i]) - get<0>(v[i + 1]));
        auto t = make_tuple(get<2>(v[i]), get<2>(v[i + 1]), c);
        e.push_back(t);
    }
    sort(v.begin(), v.end(), [](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) { return get<1>(a) < get<1>(b); });
    REP(i, N - 1) {
        ll c = abs(get<1>(v[i]) - get<1>(v[i + 1]));
        auto t = make_tuple(get<2>(v[i]), get<2>(v[i + 1]), c);
        e.push_back(t);
    }

    sort(e.begin(), e.end(), [](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) { return get<2>(a) < get<2>(b); });

    UnionFind uf(N);
    ll ans = 0;
    REP(i, e.size()) {
        ll a = get<0>(e[i]);
        ll b = get<1>(e[i]);
        ll c = get<2>(e[i]);
        if (uf.same(a, b))
            continue;
        ans += c;
        uf.unit(a, b);
    }

    cout << ans << endl;
    return 0;
}