#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 'Z' - 'A' + 1;

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
    string S, T;
    cin >> S >> T;
    UnionFind uf(MAX);
    REP(i, N) {
        if (S[i] == T[i])
            continue;
        ll n = S[i] - 'A';
        ll m = T[i] - 'A';
        if (n < 0 || m < 0 || n >= MAX || m >= MAX)
            continue;
        uf.unit(n, m);
    }
    REP(i, N) {
        ll n = S[i] - 'A';
        if (n >= 0 && n < MAX) {
            n = uf.find(n);
            S[i] = 'A' + n;
        }
        ll m = T[i] - 'A';
        if (m >= 0 && m < MAX) {
            m = uf.find(m);
            T[i] = 'A' + m;
        }
    }

    REP(i, N) {
        if (S[i] == T[i])
            continue;
        ll n = S[i] - 'A';
        ll m = T[i] - 'A';
        if (n >= 0 && n < MAX) {
            char c = S[i];
            REP(j, N) {
                if (S[j] == c)
                    S[j] = T[i];
                if (T[j] == c)
                    T[j] = T[i];
            }
        }
        if (m >= 0 && m < MAX) {
            char c = T[i];
            REP(j, N) {
                if (T[j] == c)
                    T[j] = S[i];
                if (S[j] == c)
                    S[j] = S[i];
            }
        }
    }
    //cout << S << " " << T << endl;

    ll ans = 1;
    REP(i, N) {
        if (S[i] >= 'A' && S[i] <= 'Z') {
            ll t = 10;
            if (i == 0)
                t--;
            ans *= t;
            char c = S[i];
            REP(j, N) {
                if (S[j] == c)
                    S[j] = '0';
            }
        }
    }
    cout << ans << endl;

    return 0;
}