#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool R[1505][1505];
bool B[1505][1505];
bool A0[1505][1505];
bool A1[1505][1505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, N, M;
    cin >> H >> W >> N >> M;

    memset(R, 0, sizeof(R));
    memset(B, 0, sizeof(B));
    memset(A0, 0, sizeof(A0));
    memset(A1, 0, sizeof(A1));
    REP(i, N) {
        ll a, b;
        cin >> a >> b;
        R[a - 1][b - 1] = true;
    }
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        B[a - 1][b - 1] = true;
    }
    REP(i, H) {
        REP(j, W) {
            if (B[i][j])
                continue;
            bool e = R[i][j];
            if (j > 0)
                e = (e || A0[i][j - 1]);
            A0[i][j] = (e || A0[i][j]);
        }
        for (ll j = W - 1; j >= 0; --j) {
            if (B[i][j])
                continue;
            A0[i][j] = (R[i][j] || A0[i][j + 1] || A0[i][j]);
        }
    }
    REP(j, W) {
        REP(i, H) {
            if (B[i][j])
                continue;
            bool e = R[i][j];
            if (i > 0)
                e = (e || A1[i - 1][j]);
            A1[i][j] = (e || A1[i][j]);
        }
        for (ll i = H - 1; i >= 0; --i) {
            if (B[i][j])
                continue;
            A1[i][j] = (R[i][j] || A1[i + 1][j] || A1[i][j]);
        }
    }
    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            if (A0[i][j] || A1[i][j])
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}