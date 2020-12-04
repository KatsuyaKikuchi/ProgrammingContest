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
ll A[105][105];
bool U[105][105];

ll x[] = {1, 1, 1, 1, 0, 0, 0, 0, -1, -1, -1, -1,};
ll y[] = {0, -1, 1, 0, -1, -1, 1, 1, 0, -1, 1, 0};

void check(ll h, ll w) {
    queue<pll> q;
    q.push(pll(h, w));
    vector<pll> v;
    bool out = false;
    U[h][w] = true;
    while (!q.empty()) {
        pll t = q.front();
        v.push_back(t);
        q.pop();
        REP(i, 6) {
            ll nx = t.first + x[2 * i + (t.first % 2)], ny = t.second + y[2 * i + (t.first % 2)];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                out = true;
                continue;
            }
            if (U[nx][ny] || A[nx][ny] == 1)
                continue;
            U[nx][ny] = true;
            q.push(pll(nx, ny));
        }
    }

    if (!out) {
        REP(i, v.size()) {
            A[v[i].first][v[i].second] = 1;
        }
    }
}

ll count(ll h, ll w) {
    queue<pll> q;
    q.push(pll(h, w));
    ll count = 0;
    U[h][w] = true;
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        REP(i, 6) {
            ll nx = t.first + x[2 * i + (t.first % 2)], ny = t.second + y[2 * i + (t.first % 2)];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                count++;
                continue;
            }
            if (A[nx][ny] == 0) {
                count++;
                continue;
            }
            if (U[nx][ny])
                continue;
            U[nx][ny] = true;
            q.push(pll(nx, ny));
        }
    }
    return count;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> W >> H;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }

    REP(i, H) {
        REP(j, W) {
            if (A[i][j] == 1)
                continue;
            if (U[i][j])
                continue;
            check(i, j);
        }
    }

    ll ans = 0;
    memset(U, 0, sizeof(U));
    REP(i, H) {
        REP(j, W) {
            if (A[i][j] == 0)
                continue;
            if (U[i][j])
                continue;
            ans += count(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}