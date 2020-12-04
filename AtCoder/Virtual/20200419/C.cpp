#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[10];

ll x[2] = {0, 1};
ll y[2] = {1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }

    queue<pll> q;
    q.push(pll(0, 0));

    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        S[t.first][t.second] = '.';
        REP(i, 2) {
            ll nx = t.first + x[i], ny = t.second + y[i];
            if (nx >= H || ny >= W)
                continue;
            if (S[nx][ny] == '.')
                continue;
            q.push(pll(nx, ny));
            break;
        }
    }

    bool suc = true;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '#')
                suc = false;
        }
    }
    if (suc)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}