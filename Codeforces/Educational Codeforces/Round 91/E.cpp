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

        parent[y] = x;
    }

    vector<int> rank;
    vector<int> parent;
};

ll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> V(M);
    REP(i, N) {
        cin >> A[i];
        A[i]--;
        V[A[i]].push_back(i);
    }
    ll val = 0;
    REP(i, N - 1) {
        if (A[i] != A[i + 1])
            val++;
    }

    UnionFind uf(M);

    cout << val << endl;
    REP(_, M - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        if (V[a].size() < V[b].size()) {
            REP(i, V[a].size()) {
                ll n = V[a][i];
                if (n > 0 && uf.find(A[n - 1]) == b)
                    val--;
                if (n < N - 1 && uf.find(A[n + 1]) == b)
                    val--;
                V[b].push_back(n);
            }
            V[a].clear();
            swap(V[a], V[b]);
        }
        else {
            REP(i, V[b].size()) {
                ll n = V[b][i];
                if (n > 0 && uf.find(A[n - 1]) == a)
                    val--;
                if (n < N - 1 && uf.find(A[n + 1]) == a)
                    val--;
                V[a].push_back(n);
            }
            V[b].clear();
        }
        uf.unit(a, b);
        cout << val << endl;
    }
    return 0;
}