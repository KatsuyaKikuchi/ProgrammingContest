#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

double dp[105][105][105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, C;
    cin >> A >> B >> C;
    REP(i, 101) {
        REP(j, 101) {
            REP(k, 101) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[A][B][C] = 1;

    for (ll a = A; a < 100; ++a) {
        for (ll b = B; b < 100; ++b) {
            for (ll c = C; c < 100; ++c) {
                double div = 1.0 / (double) (a + b + c);
                dp[a + 1][b][c] += dp[a][b][c] * div * a;
                dp[a][b + 1][c] += dp[a][b][c] * div * b;
                dp[a][b][c + 1] += dp[a][b][c] * div * c;
            }
        }
    }

    double ans = 0;
    FOR(b, 100, B) {
        FOR(c, 100, C) {
            ll n = 100 + b + c - (A + B + C);
            ans += n * dp[100][b][c];
        }
    }
    FOR(a, 100, A) {
        FOR(c, 100, C) {
            ll n = 100 + a + c - (A + B + C);
            ans += n * dp[a][100][c];
        }
    }
    FOR(a, 100, A) {
        FOR(b, 100, B) {
            ll n = 100 + b + a - (A + B + C);
            ans += n * dp[a][b][100];
        }
    }
    cout << OF64 << ans << endl;
    return 0;
}