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
    vector<ll> node;
    ll cost = 0;
    ll child = 0;
};

Vertex V[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[b].node.push_back(a);
        V[a].child++;
    }

    queue<pll> q;
    REP(i, N) {
        if (V[i].child == 0)
            q.push(pll(i, 0));
    }
    ll ans = 0;
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        ans = std::max(ans, t.second);
        ll cost = t.second + 1;
        for (auto &n : V[t.first].node) {
            V[n].cost = std::max(V[n].cost, cost);
            if (--V[n].child > 0)
                continue;
            q.push(pll(n, V[n].cost));
        }
    }
    cout << ans << endl;
    return 0;
}