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
ll A[55][55];
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};
ll C[55][55];

struct Data {
    pll g;
    ll cost;
};

ll getCost(pll s, pll e) {
    priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) { return a.cost > b.cost; });
    REP(i, H) {
        REP(j, W) {
            C[i][j] = INF;
        }
    }
    C[s.first][s.second] = 0;
    q.push(Data{s, 0});
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (C[t.g.first][t.g.second] < t.cost)
            continue;
        REP(i, 4) {
            ll nx = x[i] + t.g.first, ny = y[i] + t.g.second;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;
            ll cost = t.cost + A[nx][ny];
            if (C[nx][ny] <= cost)
                continue;
            C[nx][ny] = cost;
            q.push(Data{pll(nx, ny), cost});
        }
        if (C[e.first][e.second] < INF)
            break;
    }
    return C[e.first][e.second];
}

ll getCost(pll t) {
    return getCost(pll(H - 1, 0), t) + getCost(pll(0, W - 1), t) + getCost(pll(H - 1, W - 1), t) -
           2 * A[t.first][t.second];
}

int main() {
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }

    ll ans = INF;
    REP(i, H) {
        REP(j, W) {
            //! (i,j)を経由する
            ans = std::min(ans, getCost(pll(i, j)));
        }
    }
    cout << ans << endl;
    return 0;
}