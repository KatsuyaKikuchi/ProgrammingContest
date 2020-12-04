#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 500;

struct Data {
    pll g;
    ll cost;
};
ll A[MAX][MAX];
bool B[MAX][MAX];


ll dx[6] = {1, 0, -1, 1, -1, 0};
ll dy[6] = {1, 1, 1, 0, 0, -1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X, Y;
    cin >> N >> X >> Y;

    REP(i, MAX) {
        REP(j, MAX) {
            A[i][j] = INF;
        }
    }

    ll origin = MAX / 2;
    X += origin;
    Y += origin;
    memset(B, 0, sizeof(B));
    REP(i, N) {
        ll x, y;
        cin >> x >> y;
        B[x + origin][y + origin] = true;
    }

#if false
    REP(i, MAX) {
        REP(j, MAX) {
            if (i == origin && j == origin)
                cout << 'S';
            else if (B[i][j])
                cout << "#";
            else if (i == X && j == Y)
                cout << "G";
            else
                cout << '.';
        }
        cout << endl;
    }
#endif

    queue<Data> q;
    q.push(Data{pll(origin, origin), 0});
    A[origin][origin] = 0;
    while (!q.empty()) {
        auto d = q.front();
        q.pop();
        ll cost = d.cost + 1;
        REP(i, 6) {
            ll nx = d.g.first + dx[i], ny = d.g.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX)
                continue;
            if (B[nx][ny])
                continue;
            if (A[nx][ny] <= cost)
                continue;
            A[nx][ny] = cost;
            q.push(Data{pll(nx, ny), cost});
        }
    }

    if (A[X][Y] == INF)
        cout << -1 << endl;
    else
        cout << A[X][Y] << endl;
    return 0;
}