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

ll N;
ll A[10004];
ll L[100005];
bool U[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    ll mx = 0;
    REP(i, N) {
        cin >> A[i];
        mx = std::max(A[i], mx);
    }
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first < b.first; });
    REP(i, N) {
        q.push(pll(A[i], i));
    }

    memset(L, 0, sizeof(L));
    memset(U, 0, sizeof(U));
    UnionFind uf(N);
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        ll n = t.first;
        ll idx = t.second;
        ll sum = 1;
        if (idx > 0) {
            if (U[idx - 1]) {
                ll p = uf.find(idx - 1);
                sum += uf.size(idx - 1);
                uf.unit(idx, idx - 1);
            }
        }
        if (idx < N - 1) {
            if (U[idx + 1]) {
                ll p = uf.find(idx + 1);
                sum += uf.size(idx + 1);
                uf.unit(idx, idx + 1);
            }
        }
        L[n] = std::max(L[n], sum);
        U[idx] = true;
    }

    for (ll i = mx; i >= 0; --i) {
        L[i] = std::max(L[i], L[i + 1]);
    }

    ll ans = 0;
    REP(i, mx + 1) {
        ans = std::max(ans, L[i] * i);
    }
    cout << ans << endl;
    return 0;
}