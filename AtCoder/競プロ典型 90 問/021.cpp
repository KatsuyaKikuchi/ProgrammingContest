#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

stack<ll> stk;
bool seen[100005];

ll dfs(const vector<vector<ll>> &graph, ll index, ll value, ll parent = -1) {
    seen[index] = true;
    for (auto &nxt:graph[index]) {
        if (seen[nxt])
            continue;
        value = dfs(graph, nxt, value, index);
    }
    stk.push(index);
    return value + 1;
}

ll solve(const vector<vector<ll>> &graph) {
    ll ret = 0;
    memset(seen, 0, sizeof(seen));
    while (!stk.empty()) {
        ll t = stk.top();
        stk.pop();
        if (seen[t])
            continue;
        ll count = 0;
        seen[t] = true;
        queue<ll> q;
        q.push(t);
        while (!q.empty()) {
            ll index = q.front();
            count++;
            q.pop();
            for (auto &nxt:graph[index]) {
                if (seen[nxt])
                    continue;
                seen[nxt] = true;
                q.push(nxt);
            }
        }

        ret += count * (count - 1) / 2;
    }
    return ret;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> to(N), from(N);
    memset(seen, 0, sizeof(seen));
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        from[b].push_back(a);
    }
    ll value = 0;
    REP(i, N) {
        if (seen[i])
            continue;
        value = dfs(to, i, value);
    }

    ll ans = solve(from);
    cout << ans << endl;
    return 0;
}