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

ll A[105][105];

int main() {
    ll H, W;
    cin >> H >> W;
    pll s, g;
    cin >> s.first >> s.second;
    cin >> g.first >> g.second;
    s.first--;
    s.second--;
    g.first--;
    g.second--;
    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
            ans += A[i][j];
        }
    }

    vector<tuple<ll, ll, ll>> v;
    REP(i, H) {
        REP(j, W) {
            if (j < W - 1) {
                //! <->
                ll a = i * W + j, b = i * W + j + 1;
                ll c = A[i][j] * A[i][j + 1];
                v.push_back(make_tuple(a, b, c));
            }
            if (i < H - 1) {
                ll a = i * W + j, b = (i + 1) * W + j;
                ll c = A[i][j] * A[i + 1][j];
                v.push_back(make_tuple(a, b, c));
            }
        }
    }

    sort(v.begin(), v.end(), [](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) { return get<2>(a) > get<2>(b); });
    UnionFind uf(H * W);

    REP(i, v.size()) {
        auto t = v[i];
        ll a = get<0>(t);
        ll b = get<1>(t);
        ll c = get<2>(t);

        if (uf.same(a, b))
            continue;
        ans += c;
        uf.unit(a, b);
    }
    cout << ans << endl;

    return 0;
}