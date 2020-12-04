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

Vertex V[100005];
ll C[100005][3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
    }
    ll S, T;
    cin >> S >> T;
    S--;
    T--;
    REP(i, N) {
        REP(j, 3) {
            C[i][j] = INF;
        }
    }

    C[S][0] = 0;
    queue<pll> q;
    q.push(pll(S, 0));
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        ll cost = t.second + 1;
        REP(i, V[t.first].node.size()) {
            ll n = V[t.first].node[i];
            if (C[n][cost % 3] <= cost)
                continue;
            C[n][cost % 3] = cost;
            q.push(pll(n, cost));
        }
    }

    if (C[T][0] == INF)
        cout << -1 << endl;
    else
        cout << C[T][0] / 3 << endl;
    return 0;
}