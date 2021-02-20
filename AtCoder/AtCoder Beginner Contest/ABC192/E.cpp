#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

struct Edge {
    ll n;
    ll t;
    ll k;

    Edge(ll n, ll t, ll k) : n(n), t(t), k(k) {}
};

struct Vertex {
    vector<Edge> edge;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<Vertex> V(N);
    REP(i, M) {
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        a--;
        b--;
        V[a].edge.push_back(Edge(b, t, k));
        V[b].edge.push_back(Edge(a, t, k));
    }
    X--;
    Y--;
    vector<ll> dist(N, INF);
    dist[X] = 0;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(X, 0));
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (dist[t.first] < t.second)
            continue;
        for (auto &e:V[t.first].edge) {
            ll nxt = e.n;
            ll ti = e.t;
            ll k = e.k;
            ll cost = INF;
            if (t.second % k == 0) {
                cost = t.second + ti;
            }
            else {
                ll d = t.second % k;
                cost = t.second + k - d + ti;
            }
            if (dist[nxt] <= cost)
                continue;
            dist[nxt] = cost;
            q.push(pll(nxt, cost));
        }
    }
    ll ans = dist[Y];
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}