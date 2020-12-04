#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[105];
ll x[2] = {0, 1};
ll y[2] = {1, 0};
ll M[105][105];

struct Data {
    pll g;
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

    REP(i, H) {
        REP(j, W) {
            M[i][j] = INF;
        }
    }

    ll c = 0;
    if (S[0][0] == '#')
        c++;
    priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) { return a.cost > b.cost; });
    q.push(Data{pll(0, 0), c});
    while (!q.empty()) {
        Data t = q.top();
        q.pop();
        REP(i, 2) {
            ll nx = t.g.first + x[i], ny = t.g.second + y[i];
            if (nx >= H || ny >= W)
                continue;
            ll cost = t.cost;
            if (S[t.g.first][t.g.second] != S[nx][ny] && S[nx][ny] == '#')
                cost++;
            if (M[nx][ny] <= cost)
                continue;
            M[nx][ny] = cost;
            q.push(Data{pll(nx, ny), cost});
        }
    }

    cout << M[H - 1][W - 1] << endl;

    return 0;
}