//!******************************************************
//! MEMO
//! ダイクストラ
//!******************************************************

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
    ll N, M, R;
    cin >> N >> M >> R;
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        V[a].node.push_back(pll(b, c));
    }
    REP(i, N) {
        C[i] = INF;
    }

    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });

    q.push(pll(R, 0));
    while (!q.empty()) {
        pll t = q.top();
        q.pop();

        if (C[t.first] <= t.second)
            continue;
        C[t.first] = t.second;
        REP(i, V[t.first].node.size()) {
            pll n = V[t.first].node[i];
            ll c = t.second + n.second;
            if (C[n.first] <= c)
                continue;
            q.push(pll(n.first, c));
        }
    }

    REP(i, N) {
        if (C[i] == INF)
            cout << "INF" << endl;
        else
            cout << C[i] << endl;
    }

    return 0;
}