#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H, W;
string S[30];
bool U[25][25];

ll x[4] = {1, 0, -1, 0};
ll y[4] = {0, 1, 0, -1};

struct Data {
    pll g;
    ll c;
};

ll solve(pll s, pll g) {
    memset(U, 0, sizeof(U));
    queue<Data> q;
    q.push(Data{s, 0});
    U[s.first][s.second] = true;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        if (t.g.first == g.first && t.g.second == g.second) {
            return t.c;
        }
        REP(i, 4) {
            ll nx = t.g.first + x[i];
            ll ny = t.g.second + y[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;
            if (S[nx][ny] == '#' || U[nx][ny])
                continue;
            U[nx][ny] = true;
            q.push(Data{pll(nx, ny), t.c + 1});
        }
    }

    return 0;
}

int main() {
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }

    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '#')
                continue;
            REP(k, H) {
                REP(l, W) {
                    if (S[i][j] == '#')
                        continue;
                    ans = std::max(ans, solve(pll(i, j), pll(k, l)));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}