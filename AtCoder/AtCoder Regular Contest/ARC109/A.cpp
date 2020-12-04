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
    vector<pll> edge;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, X, Y;
    cin >> A >> B >> X >> Y;

    vector<Vertex> V(300);
    ll x = 100;
    REP(i, x) {
        V[i].edge.push_back(pll(i + x, X));
        V[i + x].edge.push_back(pll(i, X));
    }
    REP(i, x - 1) {
        V[i + 1].edge.push_back(pll(i + x, X));
        V[i + x].edge.push_back(pll(i + 1, X));
        V[i].edge.push_back(pll(i + 1, Y));
        V[i + 1].edge.push_back(pll(i, Y));
        V[i + x].edge.push_back(pll(i + x + 1, Y));
        V[i + x + 1].edge.push_back(pll(i + x, Y));
    }
    A--;
    B = B - 1 + x;

    vector<ll> d(3 * x, INF);
    d[A] = 0;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(A, 0));
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (d[t.first] < t.second)
            continue;
        REP(i, V[t.first].edge.size()) {
            pll y = V[t.first].edge[i];
            ll nxt = y.first;
            ll cost = y.second + t.second;
            if (d[nxt] <= cost)
                continue;
            d[nxt] = cost;
            q.push(pll(nxt, cost));
        }
    }
    cout << d[B] << endl;
    return 0;
}