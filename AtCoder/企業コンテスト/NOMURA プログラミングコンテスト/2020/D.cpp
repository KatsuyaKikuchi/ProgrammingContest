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
        num.assign(n, 1);
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
            num[y] += num[x];
        }
        else {
            parent[y] = x;
            num[x] += num[y];
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    vector<int> rank;
    vector<int> parent;
    vector<int> num;
};

ll P[5005];

ll modpow(ll n, ll r) {
    ll ret = 1;
    ll p = n;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % MOD;
        p = (p * p) % MOD;
        r >>= 1;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll k = 0;
    UnionFind uf(N);
    vector<ll> v;
    REP(i, N) {
        cin >> P[i];
        if (P[i] > 0 && !uf.same(i, P[i] - 1)) {
            uf.unit(i, P[i] - 1);
            k++;
        }
        else if (P[i] == -1)
            v.push_back(i);
    }
    //cout << k << endl;
    ll ans = k * modpow(N - 1, v.size()) % MOD;
    REP(i, v.size()) {
        ll n = 0;
        REP(j, N) {
            if (uf.same(j, v[i]))
                continue;
            n++;
        }
        ans += n * modpow(N - 1, v.size() - 1);// % MOD;
        //ans %= MOD;
    }

    cout << ans << endl;
    REP(i, v.size()) {
        FOR(j, v.size(), i + 1) {
            if (uf.same(v[i], v[j]))
                continue;
            ans = MOD + ans - (uf.num[uf.find(v[i])] * uf.num[uf.find(v[j])] * modpow(N - 1, v.size() - 2)) % MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}