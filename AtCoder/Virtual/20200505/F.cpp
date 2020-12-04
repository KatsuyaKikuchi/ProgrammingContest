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
    vector<pll> cost;
};

Vertex V[100005];
ll Y[100005];
ll C[100005];
ll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, S, T;
    cin >> N >> M >> S >> T;
    S--;
    T--;
    REP(i, M) {
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        V[u].node.push_back(v);
        V[u].cost.push_back(pll(a, b));
        V[v].node.push_back(u);
        V[v].cost.push_back(pll(a, b));
    }
    REP(i, N) {
        Y[i] = C[i] = INF;
    }

    {
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        Y[S] = 0;
        q.push(pll(S, 0));
        while (!q.empty()) {
            pll t = q.top();
            q.pop();

            if (Y[t.first] < t.second)
                continue;

            REP(i, V[t.first].node.size()) {
                ll n = V[t.first].node[i];
                ll cost = V[t.first].cost[i].first + t.second;
                if (Y[n] <= cost)
                    continue;
                Y[n] = cost;
                q.push(pll(n, cost));
            }
        }
    }
    {
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        C[T] = 0;
        q.push(pll(T, 0));
        while (!q.empty()) {
            pll t = q.top();
            q.pop();

            if (C[t.first] < t.second)
                continue;

            REP(i, V[t.first].node.size()) {
                ll n = V[t.first].node[i];
                ll cost = V[t.first].cost[i].second + t.second;
                if (C[n] <= cost)
                    continue;
                C[n] = cost;
                q.push(pll(n, cost));
            }
        }
    }

    A[N] = INF;
    for (ll i = N - 1; i >= 0; --i) {
        A[i] = std::min(A[i + 1], C[i] + Y[i]);
    }

    REP(i, N) {
        cout << INF - A[i] << endl;
    }
    return 0;
}