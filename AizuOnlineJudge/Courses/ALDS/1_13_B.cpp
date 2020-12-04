#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 3;
ll LIMIT = 35;

ll A[MAX][MAX];
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

ll dfs(pll s, ll match, pll prev = pll(-1, -1), ll cnt = 0) {
    if (match == MAX * MAX - 1) {
        return cnt;
    }
    if (LIMIT <= cnt)
        return INF;
    if (LIMIT < cnt + (MAX - s.first - 1) + (MAX - s.second - 1))
        return INF;

    ll ret = INF;
    REP(i, 4) {
        ll nx = x[i] + s.first, ny = y[i] + s.second;
        if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX)
            continue;
        if (prev.first == nx && prev.second == ny)
            continue;
        ll m = match;
        if (A[nx][ny] == nx * MAX + ny + 1)
            m--;
        else if (A[nx][ny] == s.first * MAX + s.second + 1)
            m++;
        swap(A[s.first][s.second], A[nx][ny]);
        ret = std::min(ret, dfs(pll(nx, ny), m, s, cnt + 1));
        swap(A[s.first][s.second], A[nx][ny]);
    }
    LIMIT = std::min(LIMIT, ret);
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    pll s;
    REP(i, MAX) {
        REP(j, MAX) {
            cin >> A[i][j];
            if (A[i][j] == 0)
                s = pll(i, j);
        }
    }

    ll match = 0;
    REP(i, MAX) {
        REP(j, MAX) {
            ll num = i * MAX + j + 1;
            if (A[i][j] == num)
                match++;
        }
    }

    cout << dfs(s, match) << endl;
    return 0;
}