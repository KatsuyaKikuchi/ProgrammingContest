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
    ll to;
    ll c;
    ll d;
};

struct Vertex {
    vector<Edge> edge;
};

Vertex V[100005];

ll func(ll x, ll c, ll d) {
    return x + c + (d / (1 + x));
}

ll calc(ll time, ll cost, ll d) {
    if (time >= d) {
        return time + cost + (d / (time + 1));
    }
    ll t = std::max((ll) sqrt(d) - 5, time);
    ll ret = func(t, cost, d);
    REP(j, 10) {
        ret = std::min(ret, func(t + j, cost, d));
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        V[a].edge.push_back(Edge{b, c, d});
        V[b].edge.push_back(Edge{a, c, d});
    }
    vector<ll> D(N + 5, INF);
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    D[0] = 0;
    q.push(pll(0, 0));
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (D[t.first] < t.second)
            continue;
        for (auto &e : V[t.first].edge) {
            ll cost = calc(t.second, e.c, e.d);
            // cout << cost << endl;
            if (D[e.to] <= cost)
                continue;
            D[e.to] = cost;
            q.push(pll(e.to, cost));
        }
    }

    ll ans = D[N - 1];
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}