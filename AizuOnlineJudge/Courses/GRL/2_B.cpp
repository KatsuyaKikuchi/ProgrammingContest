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

Vertex V[105];
bool U[105];
ll C[105];

int main() {
    ll N, M, R;
    cin >> N >> M >> R;
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        V[a].node.push_back(pll(b, c));
    }

    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    REP(i, N) {
        C[i] = INF;
    }
    REP(i, V[R].node.size()) {
        pll n = V[R].node[i];
        q.push(n);
        C[n.first] = n.second;
    }
    memset(U, 0, sizeof(U));
    U[R] = true;
    ll ans = 0;
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (U[t.first])
            continue;
        U[t.first] = true;
        ans += C[t.first];
        REP(i, V[t.first].node.size()) {
            pll n = V[t.first].node[i];
            if (U[n.first])
                continue;
            q.push(pll(n.first, t.second + n.second));
            C[n.first] = std::min(C[n.first], n.second);
        }
    }
    cout << ans << endl;
    return 0;
}