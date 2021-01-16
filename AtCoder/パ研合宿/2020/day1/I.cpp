#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 2;

string S[2005];
ll dist[2005][2005][MAX];
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

struct Data {
    pll g;
    ll dir;
    ll cost;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    pll s, g;
    cin >> s.first >> s.second >> g.first >> g.second;
    s.first--;
    s.second--;
    g.first--;
    g.second--;
    REP(i, H) {
        cin >> S[i];
    }
    REP(i, H) {
        REP(j, W) {
            REP(k, MAX) {
                dist[i][j][k] = INF;
            }
        }
    }

    queue<Data> q;
    q.push(Data{s, -1, 0});
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        ll cost = t.cost + 1;
        REP(i, 4) {
            ll nx = t.g.first + x[i], ny = t.g.second + y[i];
            if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                continue;
            if (S[nx][ny] == '#')
                continue;
            if (t.dir == (i % 2))
                continue;
            if (dist[nx][ny][i % 2] <= cost)
                continue;
            dist[nx][ny][i % 2] = cost;
            q.push(Data{pll(nx, ny), i % 2, cost});
        }
    }

    ll ans = INF;
    REP(i, MAX) {
        ans = std::min(ans, dist[g.first][g.second][i]);
    }
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}