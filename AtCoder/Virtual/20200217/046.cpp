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
    vector<pll> node;
};

Vertex V0[100005], V1[100005];
ll C0[100005], C1[100005];
ll C[100005];

int main() {
    ll N, M, S, T;
    cin >> N >> M >> S >> T;
    S--;
    T--;
    REP(i, M) {
        ll a, b, x, y;
        cin >> x >> y >> a >> b;
        x--;
        y--;
        V0[x].node.push_back(pll(y, a));
        V0[y].node.push_back(pll(x, a));
        V1[x].node.push_back(pll(y, b));
        V1[y].node.push_back(pll(x, b));
    }

    REP(i, N) {
        C0[i] = C1[i] = INF;
    }
    C0[S] = C1[T] = 0;

    {
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        q.push(pll(S, 0));
        while (!q.empty()) {
            pll t = q.top();
            q.pop();
            if (C0[t.first] < t.second)
                continue;
            REP(i, V0[t.first].node.size()) {
                pll n = V0[t.first].node[i];
                ll cost = n.second + t.second;
                if (C0[n.first] <= cost)
                    continue;
                C0[n.first] = cost;
                q.push(pll(n.first, cost));
            }
        }
    }
    {
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        q.push(pll(T, 0));
        while (!q.empty()) {
            pll t = q.top();
            q.pop();
            if (C1[t.first] < t.second)
                continue;
            REP(i, V1[t.first].node.size()) {
                pll n = V1[t.first].node[i];
                ll cost = n.second + t.second;
                if (C1[n.first] <= cost)
                    continue;
                C1[n.first] = cost;
                q.push(pll(n.first, cost));
            }
        }
    }

    REP(i, N) {
        C[i] = C0[i] + C1[i];
    }

    for (ll i = N - 2; i >= 0; --i) {
        C[i] = std::min(C[i], C[i + 1]);
    }

    REP(i, N) {
        cout << INF - C[i] << endl;
    }

    return 0;
}