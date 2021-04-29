#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct UnionFind {
    UnionFind(int n) {
        rank.assign(n, 0);
        count.assign(n, 1);
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

    int size(int x) {
        x = find(x);
        return count[x];
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

bool U[2005][2005];
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    UnionFind uf(H * W);
    memset(U, 0, sizeof(U));
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll r, c;
            cin >> r >> c;
            r--;
            c--;
            U[r][c] = true;
            ll index = r * W + c;
            REP(i, 4) {
                ll nr = r + x[i], nc = c + y[i];
                if (nr < 0 || nc < 0 || nr >= H || nc >= W)
                    continue;
                if (U[nr][nc]) {
                    ll idx = nr * W + nc;
                    uf.unit(idx, index);
                }
            }
        }
        else {
            ll r0, c0, r1, c1;
            cin >> r0 >> c0 >> r1 >> c1;
            r0--;
            c0--;
            r1--;
            c1--;
            ll idx0 = r0 * W + c0;;
            ll idx1 = r1 * W + c1;
            if (uf.same(idx0, idx1) && U[r0][c0] && U[r1][c1])
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}