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

Vertex V[100005];
ll C[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, L;
    cin >> N >> L;
    REP(i, L) {
        V[i + 1].node.push_back(pll(i, 0));
        C[i + 1] = INF;
    }
    REP(i, N) {
        ll a, b, c;
        cin >> a >> b >> c;
        V[a].node.push_back(pll(b, c));
    }

    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(0, 0));
    C[0] = 0;
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (C[t.first] < t.second)
            continue;
        REP(i, V[t.first].node.size()) {
            ll n = V[t.first].node[i].first;
            ll cost = V[t.first].node[i].second + t.second;
            if (C[n] <= cost)
                continue;
            C[n] = cost;
            q.push(pll(n, cost));
        }
    }

    cout << C[L] << endl;
    return 0;
}