#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

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

        parent[x] = y;
    }

    vector<int> rank;
    vector<int> parent;
};

ll T[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll sum = 0;
    memset(T, 0, sizeof(T));
    REP(i, N) {
        cin >> A[i];
        sum += A[i];
        T[A[i]]++;
    }

    // UnionFind uf(100005);

    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll b, c;
        cin >> b >> c;

        sum -= b * T[b];
        sum += c * T[b];
        T[c] += T[b];
        T[b] = 0;
        cout << sum << endl;
    }
    return 0;
}