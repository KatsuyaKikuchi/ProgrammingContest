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
    ll p = -1;
    vector<ll> node;
    ll depth = -1;
};

void dfs(ll idx, ll depth, vector<Vertex> &graph) {
    graph[idx].depth = depth;
    for (auto &nxt:graph[idx].node) {
        dfs(nxt, depth + 1, graph);
    }
}

struct Query {
    ll index;
    ll U, D;
};

void solve(ll idx, vector<Vertex> &graph, vector<vector<ll>> &count) {
    ll index = -1;
    for (auto &nxt:graph[idx].node) {
        if (index < 0 || count[index].size() < count[nxt].size()) {
            index = nxt;
        }
    }
    if (index >= 0) {
        //count[idx].resize(count[index].size());
        swap(count[index], count[idx]);
    }
    for (auto &nxt:graph[idx].node) {
        if (index == nxt)
            continue;
        REP(i, count[nxt].size()) {
            count[idx][count[idx].size() - 1 - i] += count[nxt][count[nxt].size() - 1 - i];
        }
    }
    count[idx].push_back(1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Vertex> V(N + 5);
    REP(i, N - 1) {
        ll p;
        cin >> p;
        p--;
        V[p].node.push_back(i + 1);
        V[i + 1].p = p;
    }
    dfs(0, 0, V);
    ll qq;
    cin >> qq;
    vector<Query> Q(qq);
    REP(i, qq) {
        Q[i].index = i;
        cin >> Q[i].U >> Q[i].D;
        Q[i].U--;
    }
    sort(Q.begin(), Q.end(), [&](Query a, Query b) { return V[a.U].depth > V[b.U].depth; });
    vector<ll> ans(qq, 0);
    vector<vector<ll>> count(N);
    ll index = 0;
    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q([&](ll a, ll b) { return V[a].depth < V[b].depth; });
    REP(i, N) {
        if (V[i].node.size() == 0)
            q.push(i);
    }
    vector<bool> U(N + 5, false);
    while (!q.empty() && index < qq) {
        while (!q.empty()) {
            auto t = q.top();
            if (V[Q[index].U].depth > V[t].depth)
                break;

            solve(t, V, count);
#if false
            cout << t << "--" << endl;
            REP(i, count[t].size()) {
                cout << count[t][i] << " ";
            }
            cout << endl;
#endif
            q.pop();
            if (V[t].p >= 0 && !U[V[t].p]) {
                q.push(V[t].p);
                U[V[t].p] = true;
            }
        }

        ll dep = V[Q[index].U].depth;
        while (index < qq && V[Q[index].U].depth == dep) {
            ll idx = Q[index].U;
            ll dep2 = V[idx].depth;
            ll depIdx = count[idx].size() - 1 - (Q[index].D - dep2);
            // cout << depIdx << " " << Q[index].index << endl;
            if (0 <= depIdx && depIdx < count[idx].size()) {
                ans[Q[index].index] = count[idx][depIdx];
            }
            index++;
        }
    }

    REP(i, qq) {
        cout << ans[i] << endl;
    }
    return 0;
}