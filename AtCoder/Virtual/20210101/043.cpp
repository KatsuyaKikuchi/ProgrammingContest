#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<pll> node;
};

ll N, M;
Vertex V[1005];

ll X[1005], Y[1005];

void solve(ll *dist, ll s) {
    dist[s] = 0;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first > b.first; });
    q.push(pll(0, s));
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (dist[t.second] < t.first)
            continue;
        REP(i, V[t.second].node.size()) {
            ll nxt = V[t.second].node[i].first;
            ll cost = t.first + V[t.second].node[i].second;
            if (dist[nxt] <= cost)
                continue;
            dist[nxt] = cost;
            q.push(pll(cost, nxt));
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    ll S, T;
    cin >> S >> T;
    S--;
    T--;
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].node.push_back(pll(b, c));
        V[b].node.push_back(pll(a, c));
    }

    REP(i, N) {
        X[i] = Y[i] = INF;
    }
    solve(X, S);
    solve(Y, T);

    ll ans = -1;
    REP(i, N) {
        if (X[i] == Y[i] && X[i] < INF)
            ans = i + 1;
    }
    cout << ans << endl;
    return 0;
}