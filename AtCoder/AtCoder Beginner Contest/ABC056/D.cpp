#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[5005];
bool dpL[5005][5005];
bool dpR[5005][5005];
ll S[5005][5005];

int main() {
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }
    memset(dpL, 0, sizeof(dpL));
    dpL[0][0] = true;
    REP(i, N) {
        REP(j, K) {
            dpL[i + 1][j] |= dpL[i][j];
            ll n = j + A[i];
            if (dpL[i][j] && n < K)
                dpL[i + 1][n] = true;
        }
    }

    memset(dpR, 0, sizeof(dpR));
    dpR[N + 1][0] = true;
    REP(i, N) {
        REP(j, K) {
            dpR[N - i][j] |= dpR[N - i + 1][j];
            ll n = j + A[N - 1 - i];
            if (n < K && dpR[N - i + 1][j])
                dpR[N - i][n] = true;
        }
    }

    memset(S, 0, sizeof(S));
    REP(i, N + 1) {
        REP(j, K) {
            if (dpR[i + 1][j])
                S[i + 1][j + 1]++;
            S[i + 1][j + 2] += S[i + 1][j + 1];
        }
    }

    ll ans = 0;
    REP(i, N) {
        //! iを抜く
        bool need = false;
        REP(j, K) {
            if (need)
                break;
            if (!dpL[i][j])
                continue;
            //! K-A[i]以上K-1以下となる和が存在するか
            ll m = std::max(0LL, K - A[i]);
            ll l = std::max(m - j, 0LL);
            ll r = std::max(K - 1 - j, 0LL);
            if (S[i + 2][r + 1] - S[i + 2][l] > 0)
                need = true;
        }
        if (!need)
            ans++;
    }
    cout << ans << endl;
    return 0;
}