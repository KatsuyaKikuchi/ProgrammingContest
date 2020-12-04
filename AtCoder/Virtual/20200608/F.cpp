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

struct UnionFind {
    UnionFind(int n) {
        rank.assign(n, 0);
        parent.resize(n);
        cnt.assign(n, 1);
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

    ll count(int x) {
        return cnt[find(x)];
    }

    void unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        if (rank[x] < rank[y]) {
            parent[x] = y;
            cnt[y] += cnt[x];
        }
        else {
            parent[y] = x;
            cnt[x] += cnt[y];
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    vector<int> rank;
    vector<int> parent;
    vector<int> cnt;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> X;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        X.push_back(A[i].first);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    UnionFind uf(X.size());
    sort(A, A + N, [](pll a, pll b) { return a.second < b.second; });
    REP(i, N - 1) {
        if (A[i].second == A[i + 1].second) {
            ll p = lower_bound(X.begin(), X.end(), A[i].first) - X.begin();
            ll n = lower_bound(X.begin(), X.end(), A[i + 1].first) - X.begin();
            uf.unit(p, n);
        }
    }

    vector<vector<ll>> Y(X.size());
    vector<ll> count(X.size(), 0);
    REP(i, N) {
        ll p = uf.find(lower_bound(X.begin(), X.end(), A[i].first) - X.begin());
        Y[p].push_back(A[i].second);
        count[p]++;
    }

    ll ans = 0;
    vector<bool> U(X.size(), false);
    REP(i, N) {
        ll p = uf.find(lower_bound(X.begin(), X.end(), A[i].first) - X.begin());
        if (U[p])
            continue;
        U[p] = true;
        sort(Y[p].begin(), Y[p].end());
        Y[p].erase(unique(Y[p].begin(), Y[p].end()), Y[p].end());

        ans += Y[p].size() * uf.count(p) - count[p];
    }
    cout << ans << endl;

    return 0;
}