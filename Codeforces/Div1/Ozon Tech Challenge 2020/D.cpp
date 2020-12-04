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
};

ll N;
Vertex V[1005];
bool U[1005];
ll C[1005];

pll getLongest(ll root) {
    REP(i, N) {
        C[i] = INF;
    }

    ll edge0 = root;
    {
        queue<pll> q;
        q.push(pll(root, 0));
        C[root] = 0;
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            if (C[edge0] < C[t.first])
                edge0 = t.first;
            REP(i, V[t.first].node.size()) {
                ll n = V[t.first].node[i];
                if (U[n])
                    continue;
                if (C[n] <= cost)
                    continue;
                C[n] = cost;
                q.push(pll(n, cost));
            }
        }
    }
    REP(i, N) {
        C[i] = INF;
    }
    ll edge1 = edge0;
    {
        queue<pll> q;
        q.push(pll(edge0, 0));
        C[edge0] = 0;
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            if (C[edge1] < C[t.first])
                edge1 = t.first;
            REP(i, V[t.first].node.size()) {
                ll n = V[t.first].node[i];
                if (U[n])
                    continue;
                if (C[n] <= cost)
                    continue;
                C[n] = cost;
                q.push(pll(n, cost));
            }
        }
    }

    ll s = edge1;
    while (s != edge0) {
        U[s] = true;
        REP(i, V[s].node.size()) {
            ll n = V[s].node[i];
            if (C[n] == C[s] - 1) {
                s = n;
                break;
            }
        }
    }
    U[edge0] = true;
    return pll(edge0, edge1);
}

int main() {
    cin >> N;
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    ll root = 0;
    REP(i, N) {
        if (V[i].node.size() == 1)
            root = i;
    }

    REP(_, (N / 2) + 1) {
        pll p = getLongest(root);
        if (p.first == p.second) {
            cout << "! " << p.first + 1 << endl;
            break;
        }
        cout << "? " << p.first + 1 << " " << p.second + 1 << endl;
        ll w;
        cin >> w;
        U[w - 1] = false;
        root = w - 1;
    }
    return 0;
}