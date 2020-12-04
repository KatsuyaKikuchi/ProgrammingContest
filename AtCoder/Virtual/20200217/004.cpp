#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[505];
ll x[4] = {1, 0, -1, 0};
ll y[4] = {0, 1, 0, -1};
bool U[505][505];

int main() {
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }

    pll s, g;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == 's')
                s = pll(i, j);
            if (S[i][j] == 'g')
                g = pll(i, j);
        }
    }

    memset(U, 0, sizeof(U));
    queue<pll> q;
    q.push(s);
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        REP(i, 4) {
            ll nx = t.first + x[i], ny = t.second + y[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;
            if (U[nx][ny])
                continue;
            if (S[nx][ny] == '#')
                continue;
            U[nx][ny] = true;
            q.push(pll(nx, ny));
        }
    }
    if (U[g.first][g.second])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}