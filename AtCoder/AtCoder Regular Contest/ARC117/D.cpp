#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<bool> C;
ll last = 0;
vector<vector<ll>> V;
vector<ll> ans;

ll dfs(ll index, ll p, ll value = 1) {
    ans[index] = value;
    ll stk = -1;
    REP(i, V[index].size()) {
        ll nxt = V[index][i];
        if (nxt == p)
            continue;
        if (C[nxt]) {
            stk = nxt;
            continue;
        }
        value = dfs(nxt, index, value + 1);
    }
    if (stk >= 0)
        value = dfs(stk, index, value + 1);
    return value + 1;
}

bool dfs2(ll index, ll p = -1) {
    C[index] = index == last;
    REP(i, V[index].size()) {
        ll nxt = V[index][i];
        if (nxt == p)
            continue;
        C[index] = C[index] || dfs2(nxt, index);
    }
    return C[index];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    V.resize(N);
    ans.resize(N);
    C.assign(N, 0);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    ll p = 0;
    {
        vector<ll> dist(N, INF);
        dist[p] = 0;
        queue<ll> q;
        q.push(p);
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            ll cost = dist[t] + 1;
            REP(i, V[t].size()) {
                ll n = V[t][i];
                if (dist[n] <= cost)
                    continue;
                dist[n] = cost;
                if (dist[p] < dist[n])
                    p = n;
                q.push(n);
            }
        }
    }
    last = p;
    {
        vector<ll> dist(N, INF);
        dist[p] = 0;
        queue<ll> q;
        q.push(p);
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            ll cost = dist[t] + 1;
            REP(i, V[t].size()) {
                ll n = V[t][i];
                if (dist[n] <= cost)
                    continue;
                dist[n] = cost;
                if (dist[p] < dist[n])
                    p = n;
                q.push(n);
            }
        }
    }

    dfs2(p, -1);
    dfs(p, -1);
    REP(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}