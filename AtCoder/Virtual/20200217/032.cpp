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
ll S[1005][1005];
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

int main() {
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }
    memset(S, 0, sizeof(S));
    vector<pll> v;
    REP(i, H) {
        REP(j, W) {
            v.push_back(pll(i, j));
        }
    }
    sort(v.begin(), v.end(), [](pll a, pll b) {
        return A[a.first][a.second] > A[b.first][b.second];
    });
    REP(i, v.size()) {
        auto t = v[i];
        S[t.first][t.second] = 1;
        REP(i, 4) {
            ll nx = x[i] + t.first, ny = y[i] + t.second;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;
            if (A[t.first][t.second] < A[nx][ny])
                S[t.first][t.second] += S[nx][ny];
        }
        S[t.first][t.second] %= MOD;
    }

    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            ans += S[i][j];
        }
    }
    cout << ans % MOD << endl;
    return 0;
}