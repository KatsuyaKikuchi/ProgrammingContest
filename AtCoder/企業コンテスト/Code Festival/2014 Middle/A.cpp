#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void djkstra(vector<ll> &dist, ll s, const vector<vector<pll>> &graph) {
    dist[s] = 0;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(s, 0));
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (dist[t.first] < t.second)
            continue;
        for (auto &p : graph[t.first]) {
            ll nxt = p.first;
            ll cost = t.second + p.second;
            if (dist[nxt] <= cost)
                continue;
            dist[nxt] = cost;
            q.push(pll(nxt, cost));
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, S, T;
    cin >> N >> M >> S >> T;
    S--;
    T--;
    vector<vector<pll>> V(N);
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].push_back(pll(b, c));
        V[b].push_back(pll(a, c));
    }

    vector<ll> dist0(N, INF), dist1(N, INF);
    djkstra(dist0, S, V);
    djkstra(dist1, T, V);
    REP(i, N) {
        if (dist0[i] == dist1[i] && dist0[i] < INF) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}