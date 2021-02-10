#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[505][505];
ll A[505][505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, Q;
    cin >> N >> M >> Q;
    memset(S, 0, sizeof(S));
    REP(_, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        S[a][b]++;
    }
    REP(i, N) {
        REP(j, N) {
            S[i][j + 1] += S[i][j];
        }
    }
    memset(A, 0, sizeof(A));
    REP(i, N) {
        FOR(j, N, i) {
            FOR(k, j + 1, i) {
                A[i][j] += S[k][j];
            }
#if false
            FOR(a, j + 1, i) {
                FOR(b, j + 1, a) {
                    A[i][j] += S[a][b];
                }
            }
#endif
        }
    }

    REP(_, Q) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << A[a][b] << endl;
    }

    return 0;
}