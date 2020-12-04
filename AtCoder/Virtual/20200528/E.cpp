#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Edge {
    ll to;
    ll cost;
    ll index;
};

struct Vertex {
    vector<Edge> node;
};

Vertex V[105];
bool U[1005];
ll C[105];

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
        V[a].node.push_back(Edge{b, c, i});
        V[b].node.push_back(Edge{a, c, i});
    }

    REP(i, N) {
        priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> q(
                [](Edge a, Edge b) { return a.cost > b.cost; });
        q.push(Edge{i, 0, -1});
        REP(j, N) {
            C[j] = INF;
        }
        C[i] = 0;
        while (!q.empty()) {
            auto e = q.top();
            q.pop();
            if (C[e.to] < e.cost)
                continue;
            if (e.index >= 0)
                U[e.index] = true;
            REP(j, V[e.to].node.size()) {
                auto &n = V[e.to].node[j];
                ll cost = n.cost + e.cost;
                if (C[n.to] <= cost)
                    continue;
                C[n.to] = cost;
                q.push(Edge{n.to, cost, n.index});
            }
        }
    }

    ll ans = 0;
    REP(i, M) {
        if (U[i])
            continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}