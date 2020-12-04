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
    ll count = 0;
};
Vertex V[100005];
ll E[100005];
bool U[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(pll(b, i));
        V[b].node.push_back(pll(a, i));
    }

    ll index = 0;
    memset(U, 0, sizeof(U));
    queue<ll> q;
    REP(i, N) {
        if (V[i].node.size() == 1)
            q.push(i);
    }
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        U[t] = true;
        REP(i, V[t].node.size()) {
            pll n = V[t].node[i];
            if (U[n.first])
                continue;
            E[n.second] = index++;
            V[n.first].count++;
            if (V[n.first].count == V[n.first].node.size() - 1) {
                q.push(n.first);
            }
        }
    }

    REP(i, N - 1) {
        cout << E[i] << endl;
    }
    return 0;
}