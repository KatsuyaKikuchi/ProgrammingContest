#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    ll n = N * N;
    vector<ll> dist(n, INF);
    vector<vector<ll>> V(n);
    vector<vector<pll>> E(26);
    REP(i, M) {
        char c;
        ll a, b;
        cin >> a >> b >> c;
        a--;
        b--;
        E[c - 'a'].push_back(pll(a, b));
    }
    REP(c, 26) {
        REP(i, E[c].size()) {
            FOR(j, E[c].size(), i + 1) {
                vector<ll> v1 = {E[c][i].first, E[c][i].second};
                vector<ll> v0 = {E[c][j].first, E[c][j].second};
                REP(x, 2) {
                    REP(y, 2) {
                        {
                            ll idx0 = v0[x] * N + v1[y];
                            ll idx1 = v0[(x + 1) % 2] * N + v1[(y + 1) % 2];
                            V[idx0].push_back(idx1);
                            V[idx1].push_back(idx0);
                        }
                        {
                            ll idx0 = v1[x] * N + v0[y];
                            ll idx1 = v1[(x + 1) % 2] * N + v0[(y + 1) % 2];
                            V[idx0].push_back(idx1);
                            V[idx1].push_back(idx0);
                        }
                    }
                }
            }
        }
    }

    ll s = N - 1;
    dist[s] = 0;
    queue<ll> q;
    q.push(s);
    while (!q.empty()) {
        ll t = q.front();
        q.pop();

        ll cost = dist[t] + 1;
        REP(i, V[t].size()) {
            ll nxt = V[t][i];
            if (dist[nxt] <= cost)
                continue;
            dist[nxt] = cost;
            q.push(nxt);
        }
    }

    ll ans = INF;
    REP(i, N) {
        ll idx = i * N + i;
        ans = std::min(dist[idx] * 2, ans);
    }
    REP(c, 26) {
        REP(i, E[c].size()) {
            ll a = E[c][i].first, b = E[c][i].second;
            ll idx0 = a * N + b;
            ll idx1 = b * N + a;
            ans = std::min({ans, dist[idx0] * 2 + 1, dist[idx1] * 2 + 1});
        }
    }
    if (ans == INF)
        ans = -1;
    cout << ans << endl;

    return 0;
}