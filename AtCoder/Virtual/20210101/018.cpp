#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool S[105][105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, N;
    cin >> W >> H >> N;
    memset(S, 0, sizeof(S));
    REP(i, N) {
        ll x, y, z;
        cin >> x >> y >> z;
        switch (z) {
            case 1:
                REP(i, H) {
                    REP(j, x) {
                        S[i][j] = true;
                    }
                }
                break;
            case 2:
                REP(i, H) {
                    FOR(j, W, x) {
                        S[i][j] = true;
                    }
                }
                break;
            case 3:
                REP(i, y) {
                    REP(j, W) {
                        S[i][j] = true;
                    }
                }
                break;
            case 4:
                FOR(i, H, y) {
                    REP(j, W) {
                        S[i][j] = true;
                    }
                }
                break;
        }
    }

    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            if (!S[i][j])
                ans++;
        }
    }
    cout << ans << endl;

    return 0;
}