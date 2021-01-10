#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[105];
struct Vertex {
    vector<ll> edge;
};
Vertex V[105];
vector<pll> E;
vector<ll> ans;

ll nxt(pll edge, ll i) {
    if (edge.first == i)
        return edge.second;
    return edge.first;
}

void dfs(ll idx) {
    REP(i, V[idx].edge.size()) {
        ll id = V[idx].edge[i];
        if (ans[id] != 0)
            continue;
        ll n = nxt(E[id], idx);
        if (E[id].first == idx)
            ans[id] = 1;
        else
            ans[id] = -1;
        dfs(n);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    E.resize(M);
    REP(i, M) {
        cin >> E[i].first >> E[i].second;
        E[i].first--;
        E[i].second--;
    }
    REP(i, N) {
        cin >> C[i];
    }

    ans.assign(M, 0);
    REP(i, M) {
        ll a = E[i].first, b = E[i].second;
        if (C[a] == C[b]) {
            V[a].edge.push_back(i);
            V[b].edge.push_back(i);
        }
        else if (C[a] < C[b]) {
            ans[i] = -1;
        }
        else if (C[a] > C[b]) {
            ans[i] = 1;
        }
    }

    // ループの処理
    REP(i, N) {
        dfs(i);
    }

    REP(i, M) {
        if (ans[i] == 1)
            cout << "->" << endl;
        else
            cout << "<-" << endl;
    }
    return 0;
}