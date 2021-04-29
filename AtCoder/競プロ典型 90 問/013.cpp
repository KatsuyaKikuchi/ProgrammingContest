#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<vector<pll>> V;

vector<ll> dijkstra(ll start, ll size) {
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first > b.first; });
    q.push(pll(0, start));
    vector<ll> ret(size, INF);
    ret[start] = 0;
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        ll idx = t.second;
        ll cost = t.first;
        if (ret[idx] < cost)
            continue;
        for (auto &v : V[idx]) {
            ll c = cost + v.second;
            ll nxt = v.first;
            if (ret[nxt] <= c)
                continue;
            ret[nxt] = c;
            q.push(pll(c, nxt));
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    V.resize(N);
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].push_back(pll(b, c));
        V[b].push_back(pll(a, c));
    }

    auto dist0 = dijkstra(0, N);
    auto dist1 = dijkstra(N - 1, N);
    REP(i, N) {
        cout << dist0[i] + dist1[i] << endl;
    }
    return 0;
}