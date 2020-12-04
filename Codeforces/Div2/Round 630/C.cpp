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

struct Data {
    ll T[30];
};

ll solve(string &s, ll K) {
    ll N = s.length();
    ll ans = 0;
    UnionFind uf(N);
    REP(i, N) {
        uf.unit(i, N - 1 - i);
        if (i + K < N)
            uf.unit(i, i + K);
    }

    map<ll, ll> map;
    vector<Data> v;
    REP(i, N) {
        ll p = map[uf.find(i)];
        if (p == 0) {
            v.push_back(Data());
            p = v.size();

            map[uf.find(i)] = p;
        }
        v[p - 1].T[s[i] - 'a']++;
    }

    REP(i, v.size()) {
        ll sum = 0;
        ll max = 0;
        REP(j, 30) {
            sum += v[i].T[j];
            max = std::max(max, v[i].T[j]);
        }
        ans += sum - max;
    }

    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N, K;
        cin >> N >> K;
        string S;
        cin >> S;
        cout << solve(S, K) << endl;
    }
    return 0;
}