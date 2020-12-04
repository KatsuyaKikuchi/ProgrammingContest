#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100][100];
bool U[100][100];
ll H, W;
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

ll dfs(pll g, ll n = 0) {
    ll ret = n;
    REP(i, 4) {
        ll nx = x[i] + g.first, ny = y[i] + g.second;
        if (nx < 0 || nx >= H || ny < 0 || ny >= W)
            continue;
        if (U[nx][ny])
            continue;
        if (A[nx][ny] == 0)
            continue;
        U[nx][ny] = true;
        ret = std::max(ret, dfs(pll(nx, ny), n + 1));
        U[nx][ny] = false;
    }
    return ret;
}

int main() {
    cin >> W >> H;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }

    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            if (A[i][j] == 0)
                continue;
            memset(U, 0, sizeof(U));
            ans = std::max(ans, dfs(pll(i, j)));
        }
    }
    cout << ans << endl;
    return 0;
}