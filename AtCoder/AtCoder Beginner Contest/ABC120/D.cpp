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
        num.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            num[i] = 1;
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
        ll n = num[x] + num[y];
        num[x] = num[y] = n;
    }

    vector<int> rank;
    vector<int> parent;
    vector<int> num;
};

pll A[100005];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        cin >> A[i].first >> A[i].second;
        A[i].first--;
        A[i].second--;
    }

    UnionFind uf(N);
    vector<ll> ans;
    ll t = N * (N - 1) / 2;
    for (int i = M - 1; i >= 0; --i) {
        ans.push_back(t);
        if (uf.same(A[i].first, A[i].second)) {
            continue;
        }
        ll n = uf.num[uf.find(A[i].first)];
        ll m = uf.num[uf.find(A[i].second)];
        t -= n * m;
        uf.unit(A[i].first, A[i].second);
    }

    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << endl;
    }

    return 0;
}