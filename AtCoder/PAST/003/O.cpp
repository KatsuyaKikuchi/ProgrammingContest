#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[505];
ll B[505];
ll R[3];

ll X[505][3];
ll Y[505][3];

ll dp[505][505][5];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    REP(i, 3) {
        cin >> R[i];
    }

    REP(i, N) {
        REP(j, 3) {
            X[i][j] = (ll) (A[i] * pow(B[i], j + 1)) % R[j];
            Y[i][j] = (ll) (A[i] * pow(B[i], j + 1));
        }
    }

#if false
    REP(i, N) {
        REP(j, 3) {
            cout << X[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
    REP(i, N) {
        REP(j, 3) {
            cout << Y[i][j] << " ";
        }
        cout << endl;
    }
#endif

REP(i,)
    return 0;
}