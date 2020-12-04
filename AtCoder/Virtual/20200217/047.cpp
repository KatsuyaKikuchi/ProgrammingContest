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
ll A[100005];

Vertex V0[100005], V1[100005];
ll C0[100005], C1[100005];

int main() {
    ll N, M, T;
    cin >> N >> M >> T;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V0[a].node.push_back(pll(b, c));
        V1[b].node.push_back(pll(a, c));
    }

    REP(i, N) {
        C0[i] = C1[i] = INF;
    }
    C0[0] = C1[0] = 0;
    {
        priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
        q.push(pll(0, 0));
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
        q.push(pll(0, 0));
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

    ll ans = 0;
    REP(i, N) {
        ll t = T - (C0[i] + C1[i]);
        if (t <= 0)
            continue;
        ans = std::max(ans, t * A[i]);
    }
    cout << ans << endl;
    return 0;
}