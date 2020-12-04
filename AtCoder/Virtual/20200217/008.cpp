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
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};
ll M[1005][1005][15];
struct Data {
    pll g;
    ll cost;
};

int main() {
    ll H, W, N;
    cin >> H >> W >> N;
    REP(i, H) {
        cin >> S[i];
    }

    pll s;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == 'S')
                s = pll(i, j);
        }
    }
    REP(i, H) {
        REP(j, W) {
            REP(n, N) {
                M[i][j][n] = INF;
            }
        }
    }

    ll ans = 0;
    REP(n, N) {
        queue<Data> q;
        q.push(Data{s, 0});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (S[t.g.first][t.g.second] - '0' == n + 1) {
                ans += M[t.g.first][t.g.second][n];
                s = t.g;
                break;
            }
            ll cost = t.cost + 1;
            REP(i, 4) {
                ll nx = t.g.first + x[i], ny = t.g.second + y[i];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                    continue;
                if (S[nx][ny] == 'X')
                    continue;
                if (M[nx][ny][n] <= cost)
                    continue;
                M[nx][ny][n] = cost;
                q.push(Data{pll(nx, ny), cost});
            }
        }
    }
    cout << ans << endl;
    return 0;
}