#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> v(N);
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    REP(i, N) {
        vector<ll> dist(N, INF);
        dist[i] = 0;
        queue<ll> q;
        q.push(i);
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            ll cost = dist[t] + 1;
            REP(j, v[t].size()) {
                ll nxt = v[t][j];
                if (dist[nxt] <= cost)
                    continue;
                dist[nxt] = cost;
                q.push(nxt);
            }
        }
        ll ans = 0;
        REP(j, N) {
            if (dist[j] == 2)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}