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
ll A[10][10];

ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

ll dfs(pll g, ll num, pll pre = pll(-1, -1), ll cnt = 0, ll ret = 25) {
    if (num == H * W - 1)
        return cnt;
    if (ret <= cnt)
        return ret;

    ll dif = abs(H - 1 - g.first) + abs(W - 1 - g.second);
    ll dc = 25 - cnt;
    if (dc < dif)
        return ret;
    if (dc < H * W - 1 - num)
        return ret;

    REP(i, 4) {
        pll nxt(x[i] + g.first, y[i] + g.second);
        if (nxt == pre)
            continue;
        if (nxt.first < 0 || nxt.first >= H || nxt.second < 0 || nxt.second >= W)
            continue;

        ll n = num;
        if (A[nxt.first][nxt.second] == nxt.first * W + nxt.second + 1)
            n--;
        if (A[nxt.first][nxt.second] == g.first * W + g.second + 1)
            n++;
        swap(A[g.first][g.second], A[nxt.first][nxt.second]);
        ret = std::min(ret, dfs(nxt, n, g, cnt + 1));
        swap(A[g.first][g.second], A[nxt.first][nxt.second]);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }
    pll s(0, 0);
    ll num = 0;
    REP(i, H) {
        REP(j, W) {
            if (A[i][j] == 0)
                s = pll(i, j);
            ll n = i * W + j + 1;
            if (n == A[i][j])
                num++;
        }
    }

    ll ans = dfs(s, num);
    cout << ans << endl;
    return 0;
}