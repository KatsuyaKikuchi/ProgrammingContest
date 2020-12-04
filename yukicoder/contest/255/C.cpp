#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<ll> children;
    ll parent = -1;
    ll depth = 0;
};

Vertex V[1000005];

void dfs(ll node, ll depth = 0) {
    V[node].depth = depth;
    for (auto &n:V[node].children) {
        dfs(n, depth + 1);
    }
}

ll C[1000005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].children.push_back(b);
        V[b].parent = a;
    }

    ll root = 0;
    REP(i, N) {
        if (V[i].parent < 0) {
            root = i;
            break;
        }
    }

    dfs(root);
    C[0] = 0;
    REP(i, N + 2) {
        C[i + 1] = (C[i] + i + 1) % MOD;
    }

    ll ans = 0;
    REP(i, N) {
        ans = (ans + C[V[i].depth]) % MOD;
    }
    cout << ans << endl;

    return 0;
}