#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<pll> node;
};
Vertex V[2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].node.push_back(pll(b, c));
    }

    REP(i, N) {
        vector<ll> dist(N, INF);
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        q.push(pll(i, 0));
        while (!q.empty()) {
            pll t = q.top();
            q.pop();
            for (auto &v : V[t.first].node) {
                ll nxt = v.first;
                ll cost = t.second + v.second;
                if (dist[nxt] <= cost)
                    continue;
                dist[nxt] = cost;
                q.push(pll(nxt, cost));
            }
        }

        ll ret = dist[i];
        if (ret == INF)
            ret = -1;
        cout << ret << endl;
    }
    return 0;
}