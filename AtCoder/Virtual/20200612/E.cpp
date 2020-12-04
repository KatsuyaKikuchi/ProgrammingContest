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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }
    memset(dpL, 0, sizeof(dpL));
    memset(dpR, 0, sizeof(dpR));
    dpL[0][0] = true;
    REP(i, N) {
        REP(j, K + 1) {
            dpL[i + 1][j] |= dpL[i][j];
            if (j + A[i] <= K)
                dpL[i + 1][std::min(K, j + A[i])] |= dpL[i][j];
        }
    }
    dpR[N][0] = true;
    for (ll i = N - 1; i >= 0; --i) {
        REP(j, K + 1) {
            dpR[i][j] |= dpR[i + 1][j];
            dpR[i][std::min(K, j + A[i])] |= dpR[i + 1][j];
        }
    }

    ll ans = 0;
    REP(i, N) {
        vector<ll> v(K + 5, 0);
        REP(j, K + 1) {
            if (dpR[i + 1][j])
                v[j]++;
            v[j + 1] += v[j];
        }

        bool e = false;
        REP(j, K) {
            if (!dpL[i][j])
                continue;
            //! K-A[i] -> K-1
            ll m = K - 1 - j;
            ll d = K - A[i] - j - 1;
            ll s = v[m];
            if (d >= 0)
                s -= v[d];
            if (s > 0) {
                e = true;
                break;
            }
        }
        if (!e)
            ans++;
    }
    cout << ans << endl;
    return 0;
}