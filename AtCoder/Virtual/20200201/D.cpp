#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[55];
ll x[4] = {1, 0, -1, 0};
ll y[4] = {0, 1, 0, -1};
ll C[55][55];
struct Data {
    pll g;
    ll cost;
};

int main() {
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }

    ll b = 0;
    REP(i, H) {
        REP(j, W) {
            C[i][j] = INF;
            if (S[i][j] == '#')
                b++;
        }
    }

    queue<Data> q;
    q.push(Data{pll(0, 0), 0});
    while (!q.empty()) {
        auto d = q.front();
        q.pop();
        REP(i, 4) {
            ll nx = x[i] + d.g.first;
            ll ny = y[i] + d.g.second;
            if (nx < 0 || ny < 0 || nx >= H || ny >= W)
                continue;
            ll cost = d.cost + 1;
            if (S[nx][ny] == '#')
                continue;
            if (C[nx][ny] <= cost)
                continue;
            C[nx][ny] = cost;
            q.push(Data{pll(nx, ny), cost});
        }
    }

    if (C[H - 1][W - 1] == INF)
        cout << -1 << endl;
    else
        cout << H * W - (C[H - 1][W - 1] + 1) - b << endl;
    return 0;
}