#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[1005];
ll A[1005][1005];
bool U[1005][1005];

ll H, W;
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

vector<pll> dfs(pll s) {
    queue<pll> q;
    q.push(s);
    vector<pll> ret;
    U[s.first][s.second] = true;
    while (!q.empty()) {
        pll t = q.front();
        ret.push_back(t);
        q.pop();
        REP(i, 4) {
            ll nx = t.first + x[i], ny = t.second + y[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;
            if (S[nx][ny] == '#')
                continue;
            if (U[nx][ny])
                continue;
            U[nx][ny] = true;
            q.push(pll(nx, ny));
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    pll s, g;
    cin >> s.first >> s.second >> g.first >> g.second;
    s.first--;
    s.second--;
    g.first--;
    g.second--;

    memset(U, 0, sizeof(U));
    REP(i, H) {
        REP(j, W) {
            A[i][j] = INF;
        }
    }
    A[s.first][s.second] = 0;
    REP(i, H) {
        cin >> S[i];
    }

    queue<pll> q;
    q.push(s);
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        ll cost = A[t.first][t.second];
        if (U[t.first][t.second])
            continue;

        vector<pll> v = dfs(t);
        for (auto &p: v) {
            A[p.first][p.second] = std::min(cost, A[p.first][p.second]);
        }
        for (auto &p: v) {
            for (ll h = -2; h <= 2; ++h) {
                for (ll w = -2; w <= 2; ++w) {
                    ll nx = h + p.first, ny = w + p.second;
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                        continue;
                    if (S[nx][ny] == '#')
                        continue;
                    if (U[nx][ny])
                        continue;
                    if (A[nx][ny] <= cost + 1)
                        continue;
                    A[nx][ny] = std::min(cost + 1, A[nx][ny]);
                    q.push(pll(nx, ny));
                }
            }
        }
    }

    if (A[g.first][g.second] == INF)
        cout << -1 << endl;
    else
        cout << A[g.first][g.second] <<
             endl;
    return 0;
}