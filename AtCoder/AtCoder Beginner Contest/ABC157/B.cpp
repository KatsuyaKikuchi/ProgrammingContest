#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[5][5];
bool U[5][5];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 3) {
        REP(j, 3) {
            cin >> A[i][j];
        }
    }
    memset(U, 0, sizeof(U));
    ll N;
    cin >> N;
    REP(i, N) {
        ll n;
        cin >> n;
        REP(a, 3) {
            REP(b, 3) {
                if (A[a][b] == n)
                    U[a][b] = true;
            }
        }
    }

    bool e = (U[0][0] & U[1][1] & U[2][2]) || (U[2][0] & U[1][1] & U[0][2]);
    REP(i, 3) {
        e |= U[i][0] & U[i][1] & U[i][2];
        e |= U[0][i] & U[1][i] & U[2][i];
    }
    if (e)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}