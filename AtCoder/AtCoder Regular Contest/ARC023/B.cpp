#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[1005][1005];
ll B[1005][1005];

ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll R, C, D;
    cin >> R >> C >> D;
    REP(i, R) {
        REP(j, C) {
            cin >> A[i][j];
            B[i][j] = INF;
        }
    }
    B[0][0] = 0;
    queue<tuple<ll, ll, ll>> q;
    q.push(make_tuple(0, 0, 0));
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        ll cost = get<2>(t) + 1;
        REP(i, 4) {
            ll nx = get<0>(t) + x[i], ny = get<1>(t) + y[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;
            if (B[nx][ny] <= cost)
                continue;
            B[nx][ny] = cost;
            q.push(make_tuple(nx, ny, cost));
        }
    }

    ll ans = 0;
    REP(i, R) {
        REP(j, C) {
            if (B[i][j] > D)
                continue;
            if ((D - B[i][j]) % 2 == 0)
                ans = std::max(ans, A[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}