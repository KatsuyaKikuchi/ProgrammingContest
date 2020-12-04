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
pll B[100005];

struct UnionFind {
    UnionFind(int n) {
        rank.assign(n, 0);
        parent.resize(n);
        count.assign(n, 1);
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
            count[y] += count[x];
        }
        else {
            parent[y] = x;
            count[x] += count[y];
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    vector<int> rank;
    vector<int> parent;
    vector<int> count;
};

ll C[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, K;
    cin >> N >> M >> K;
    UnionFind uf(N);
    REP(i, M) {
        cin >> A[i].first >> A[i].second;
        A[i].first--;
        A[i].second--;
        uf.unit(A[i].first, A[i].second);
    }
    REP(i, K) {
        cin >> B[i].first >> B[i].second;
        B[i].first--;
        B[i].second--;
    }

    REP(i, N) {
        C[i] = uf.count[uf.find(i)] - 1;
    }
    REP(i, M) {
        C[A[i].first]--;
        C[A[i].second]--;
    }
    REP(i, K) {
        if (!uf.same(B[i].first, B[i].second))
            continue;
        C[B[i].first]--;
        C[B[i].second]--;
    }

    REP(i, N) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}