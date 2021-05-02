#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[505][505];
ll B[505][505];

struct Data {
    ll cost;
    ll x, y;
    bool e = false;

    Data(ll c, ll x, ll y, bool e = false) :
            cost(c), x(x), y(y), e(e) {}
};

ll S[505][505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll R, C;
    cin >> R >> C;
    REP(i, R) {
        REP(j, C - 1) {
            cin >> A[i][j];
        }
    }
    REP(i, R - 1) {
        REP(j, C) {
            cin >> B[i][j];
        }
    }
    REP(i, R) {
        REP(j, C) {
            S[i][j] = INF;
        }
    }

    priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) { return a.cost > b.cost; });
    q.push(Data(0, 0, 0));
    S[0][0] = 0;
    while (!q.empty()) {
        auto t = q.top();
        q.pop();

        if (S[t.x][t.y] < t.cost)
            continue;
        if (t.y < C - 1) {
            ll nx = t.x, ny = t.y + 1;
            ll cost = t.cost + A[nx][ny - 1];
            if (S[nx][ny] > cost) {
                S[nx][ny] = cost;
                q.push(Data(cost, nx, ny));
            }
        }
        if (t.y > 0) {
            ll nx = t.x, ny = t.y - 1;
            ll cost = t.cost + A[nx][ny];
            if (S[nx][ny] > cost) {
                S[nx][ny] = cost;
                q.push(Data(cost, nx, ny));
            }
        }
        if (t.x < R - 1) {
            ll nx = t.x + 1, ny = t.y;
            ll cost = t.cost + B[nx - 1][ny];
            if (S[nx][ny] > cost) {
                S[nx][ny] = cost;
                q.push(Data(cost, nx, ny));
            }
        }
        if (t.x > 0) {
            ll nx = t.x - 1, ny = t.y;
            ll cost = t.cost + 1;
            if (!t.e)
                cost++;
            if (S[nx][ny] >= cost) {
                S[nx][ny] = cost;
                q.push(Data(cost, nx, ny, true));
            }
        }

    }
    cout << S[R - 1][C - 1] << endl;
    return 0;
}