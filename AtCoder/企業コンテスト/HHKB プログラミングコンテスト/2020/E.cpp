#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[2005];

ll modpow(ll n, ll r) {
    ll ret = 1;
    ll p = n;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % MOD;
        p = (p * p) % MOD;
        r /= 2;
    }
    return ret;
}

ll A[2005][2005][4];
ll T[2005][2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    ll K = 0;
    memset(A, 0, sizeof(A));
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '#') {
                A[i][j][0] = 0;
                A[i][j][1] = 0;
                continue;
            }
            K++;
            A[i][j][0]++;
            A[i][j + 1][0] += A[i][j][0];
            A[i][j][1]++;
            A[i + 1][j][1] += A[i][j][1];
        }
    }

    for (ll i = H - 1; i >= 0; --i) {
        for (ll j = W - 1; j >= 0; --j) {
            if (S[i][j] == '#') {
                A[i][j][2] = A[i][j][3] = 0;
                continue;
            }
            A[i][j][2]++;
            A[i][j][3]++;
            if (j - 1 >= 0)
                A[i][j - 1][2] += A[i][j][2];
            if (i - 1 >= 0)
                A[i - 1][j][3] += A[i][j][3];
        }
    }
    memset(T, 0, sizeof(T));
    REP(i, H) {
        REP(j, W) {
            ll s = 0;
            REP(n, 4) {
                s += A[i][j][n];
            }
            T[i][j] = std::max(0LL, s - 3);
        }
    }

    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            ll p = (MOD + modpow(2LL, T[i][j]) - 1) % MOD;
            p = (p * modpow(2LL, K - T[i][j])) % MOD;
            ans = (ans + p) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}