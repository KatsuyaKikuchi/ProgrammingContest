#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[3][3];
ll A[3], B[3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 3) {
        REP(j, 3) {
            cin >> C[i][j];
        }
    }

    A[0] = 0;
    B[0] = C[0][0];
    A[1] = C[1][0] - B[0];
    A[2] = C[2][0] - B[0];
    B[1] = C[0][1];
    B[2] = C[0][2];

    bool e = true;
    REP(i, 3) {
        REP(j, 3) {
            if (A[i] + B[j] != C[i][j])
                e = false;
        }
    }

    if (e)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}