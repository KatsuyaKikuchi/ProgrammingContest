#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
ll B[200005];
ll P[200005];

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
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    UnionFind uf(N);
    REP(i, N) {
        cin >> P[i];
        P[i]--;
        uf.unit(i, P[i]);
    }

    vector<pll> ans;
    vector<vector<ll>> v(N);
    REP(i, N) {
        ll p = uf.find(i);
        v[p].push_back(i);
    }
    REP(i, N) {
        if (v[i].size() == 0)
            continue;
        ll mx = v[i][0];
        REP(j, v[i].size()) {
            ll idx = v[i][j];
            if (A[mx] < A[idx])
                mx = idx;
            if (A[idx] <= B[P[idx]] && idx != P[idx]) {
                cout << -1 << endl;
                return 0;
            }
        }
        while (P[mx] != mx) {
            ll idx = P[mx];
            ans.push_back(pll(idx, mx));
            swap(P[mx], P[idx]);
        }
    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }

    return 0;
}