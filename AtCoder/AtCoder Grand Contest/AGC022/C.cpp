#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;
const ll MAX = 55;

ll A[55], B[55];
ll C[55][55];
ll P[55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }

    P[0] = 1;
    FOR(i, MAX, 1) {
        P[i] = P[i - 1] * 2LL;
    }

    ll ans = 0;
    while (true) {
        REP(i, MAX) {
            REP(j, MAX) {
                C[i][j] = INF;
            }
            C[i][i] = 0;
        }
        REP(i, MAX) {
            FOR(m, MAX, 1) {
                ll t = i % m;
                C[i][t] = std::min(C[i][t], P[m]);
            }
        }
        REP(k, MAX) {
            REP(i, MAX) {
                REP(j, MAX) {
                    C[i][j] = std::min(C[i][j], C[i][k] + C[k][j]);
                }
            }
        }
        ll idx = 0;
        REP(i, N) {
            if (C[A[idx]][B[idx]] < C[A[i]][B[i]])
                idx = i;
        }
        ll value = C[A[idx]][B[idx]];
        if (value == INF) {
            ans = -1;
            break;
        }
        if (value == 0)
            break;
        ll bit = 0;
        REP(i, MAX) {
            if ((value >> i) & 1)
                bit = i;
        }
        ans += P[bit];
        P[bit] = 0;
    }
    cout << ans << endl;
    return 0;
}