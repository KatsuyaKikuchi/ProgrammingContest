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

Vertex V[1005];

ll C0[1005];
ll C1[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;

    ll S, T;
    cin >> S >> T;
    S--;
    T--;
    REP(i, M) {
        ll x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        V[x].node.push_back(pll(y, z));
        V[y].node.push_back(pll(x, z));
    }

    REP(i, N) {
        C0[i] = C1[i] = INF;
    }
    C0[S] = 0;
    C1[T] = 0;

    {
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        q.push(pll(S, 0));
        while (!q.empty()) {
            pll t = q.top();
            q.pop();
            if (C0[t.first] < t.second)
                continue;
            REP(i, V[t.first].node.size()) {
                pll n = V[t.first].node[i];
                ll nxt = n.first;
                ll cost = t.second + n.second;
                if (C0[nxt] <= cost)
                    continue;
                C0[nxt] = cost;
                q.push(pll(nxt, cost));
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
            REP(i, V[t.first].node.size()) {
                pll n = V[t.first].node[i];
                ll nxt = n.first;
                ll cost = t.second + n.second;
                if (C1[nxt] <= cost)
                    continue;
                C1[nxt] = cost;
                q.push(pll(nxt, cost));
            }
        }
    }

    REP(i, N) {
        if (C0[i] == C1[i] && C0[i] != INF) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}