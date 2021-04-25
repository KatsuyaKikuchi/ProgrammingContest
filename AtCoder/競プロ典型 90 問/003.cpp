#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<vector<ll>> V;
ll dist[100005];

ll solve(ll index) {
    ll N = V.size();
    REP(i, N) {
        dist[i] = INF;
    }
    dist[index] = 0;
    queue<ll> q;
    q.push(index);
    ll ret = index;
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        if (dist[t] > dist[ret])
            ret = t;
        ll cost = dist[t] + 1;
        for (auto &nxt:V[t]) {
            if (dist[nxt] <= cost)
                continue;
            dist[nxt] = cost;
            q.push(nxt);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    V.resize(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    ll p = solve(0);
    p = solve(p);
    cout << dist[p] + 1 << endl;
    return 0;
}