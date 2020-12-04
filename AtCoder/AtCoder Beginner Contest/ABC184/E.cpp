#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[2005];
ll D[2005][2005];

ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};
bool U[30];
vector<pll> T[30];

struct Data {
    pll p;
    ll cost;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    pll s, g;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == 'S')
                s = pll(i, j);
            if (S[i][j] == 'G')
                g = pll(i, j);
            D[i][j] = INF;

            if (S[i][j] == '.' || S[i][j] == '#' || S[i][j] == 'S' || S[i][j] == 'G')
                continue;

            ll a = S[i][j] - 'a';
            T[a].push_back(pll(i, j));
        }
    }
    memset(U, 0, sizeof(U));
    D[s.first][s.second] = 0;
    queue<Data> q;
    q.push(Data{s, 0});
    while (!q.empty()) {
        auto d = q.front();
        q.pop();
        ll cost = d.cost + 1;
        REP(i, 4) {
            ll nx = x[i] + d.p.first, ny = y[i] + d.p.second;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;
            if (S[nx][ny] == '#' || D[nx][ny] <= cost)
                continue;
            D[nx][ny] = cost;
            q.push(Data{pll(nx, ny), cost});
        }

        char c = S[d.p.first][d.p.second];
        if (c == 'S' || c == 'G' || c == '#' || c == '.')
            continue;
        ll a = c - 'a';
        if (U[a])
            continue;
        REP(i, T[a].size()) {
            pll nxt = T[a][i];
            if (D[nxt.first][nxt.second] <= cost)
                continue;
            D[nxt.first][nxt.second] = cost;
            q.push(Data{nxt, cost});
        }
        U[a] = true;
    }

    if (D[g.first][g.second] == INF)
        cout << -1 << endl;
    else
        cout << D[g.first][g.second] << endl;

    return 0;
}