#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Node {
    ll to;
    ll cost;
    ll d;
};
struct Vertex {
    vector<Node> node;
};


Vertex V[200005];
ll T[200005];
ll C[200005];

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    FOR(i, N - 1, 1) {
        cin >> T[i];
    }
    REP(i, M) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        V[a].node.push_back(Node{b, c, d});
        V[b].node.push_back(Node{a, c, d});
    }

    REP(i, N) {
        C[i] = INF;
    }
    C[0] = 0;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(0, 0));

    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (C[t.first] < t.second)
            continue;

        REP(i, V[t.first].node.size()) {
            Node p = V[t.first].node[i];
            ll n = p.to;
            ll cost = t.second + T[t.first];
            cost += (p.d - (cost % p.d)) % p.d + p.cost;
            if (C[n] <= cost)
                continue;
            C[n] = cost;

            q.push(pll(n, cost));
        }
    }

    if (C[N - 1] > K)
        cout << -1 << endl;
    else
        cout << C[N - 1] << endl;

    return 0;
}