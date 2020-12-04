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

    ll color = 0;
    queue<pll> q;
    q.push(pll(0, 0));
    memset(C, 0, sizeof(C));
    while (!q.empty()) {
        pll t = q.front();
        q.pop();

        color = std::max(color, static_cast<ll>(V[t.first].node.size()));
        ll index = 1;
        REP(i, V[t.first].node.size()) {
            pll n = V[t.first].node[i];
            if (C[n.second] > 0)
                continue;
            while (index == t.second)
                index++;
            C[n.second] = index;
            q.push(pll(n.first, index));
            index++;
        }
    }

    cout << color << endl;
    REP(i, N - 1) {
        cout << C[i] << endl;
    }
    return 0;
}