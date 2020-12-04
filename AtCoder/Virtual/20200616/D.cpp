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

Vertex V[105];
ll C[105];
ll P[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N;
    ll s, g;
    cin >> s >> g;
    s--;
    g--;
    cin >> M;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    memset(P, 0, sizeof(P));
    REP(i, N) {
        C[i] = INF;
    }
    P[s] = 1;
    C[s] = 0;
    queue<pll> q;
    q.push(pll(s, 0));
    while (!q.empty()) {
        pll t = q.front();
        q.pop();

        ll cost = t.second;
        for (auto &n:V[t.first].node) {
            if (C[n] == cost - 1)
                P[t.first] += P[n];
        }
        P[t.first] %= MOD;

        cost++;
        for (auto &n:V[t.first].node) {
            if (C[n] <= cost)
                continue;
            C[n] = cost;
            q.push(pll(n, cost));
        }
    }

    cout << P[g] << endl;
    return 0;
}