#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    pll g;
    ll c;
};

struct Length {
    pll v;
    double length;
};

Data B[50];
Data S[10];

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

double getLength(pll a, pll b, ll c0, ll c1) {
    double x = a.first - b.first;
    double y = a.second - b.second;
    double cost = sqrt(x * x + y * y);
    if (c0 == c1)
        return cost;
    return cost * 10.0;
}

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> B[i].g.first >> B[i].g.second >> B[i].c;
    }
    REP(i, M) {
        cin >> S[i].g.first >> S[i].g.second >> S[i].c;
    }

    ll P = pow(2, M);
    double ans = INF;
    REP(p, P) {
        //! pのbitで表される小さい鉄塔を使う
        vector<Data> v;
        REP(i, N) {
            v.push_back(B[i]);
        }
        REP(i, M) {
            if (((p >> i) & 1) == 1)
                v.push_back(S[i]);
        }
        UnionFind uf(v.size());
        vector<Length> L;
        REP(i, v.size()) {
            FOR(j, v.size(), i + 1) {
                Length l;
                l.v = pll(i, j);
                l.length = getLength(v[i].g, v[j].g, v[i].c, v[j].c);
                L.push_back(l);
            }
        }

        sort(L.begin(), L.end(), [](Length a, Length b) { return a.length < b.length; });
        double m = 0;
        REP(i, L.size()) {
            pll vp = L[i].v;
            if (uf.same(vp.first, vp.second))
                continue;
            uf.unit(vp.first, vp.second);
            m += L[i].length;
        }
        ans = std::min(ans, m);
    }

    cout << OF64 << ans << endl;
    return 0;
}