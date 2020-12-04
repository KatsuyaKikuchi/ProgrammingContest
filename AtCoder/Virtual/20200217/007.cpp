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
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};
ll M[55][55];
struct Data {
    pll g;
    ll cost;
};

int main() {
    ll R, C;
    cin >> R >> C;
    REP(i, R) {
        REP(j, C) {
            M[i][j] = INF;
        }
    }
    pll s, g;
    cin >> s.first >> s.second;
    s.first--;
    s.second--;
    cin >> g.first >> g.second;
    g.first--;
    g.second--;
    REP(i, R) {
        cin >> S[i];
    }

    queue<Data> q;
    q.push(Data{s, 0});
    M[s.first][s.second] = 0;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        ll cost = t.cost + 1;
        REP(i, 4) {
            ll nx = t.g.first + x[i], ny = t.g.second + y[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;
            if (S[nx][ny] == '#')
                continue;
            if (M[nx][ny] <= cost)
                continue;
            M[nx][ny] = cost;
            q.push(Data{pll(nx, ny), cost});
        }
    }

    cout << M[g.first][g.second] << endl;

    return 0;
}