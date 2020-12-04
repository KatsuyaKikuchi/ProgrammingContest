#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[505][505];
ll A[3][3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;

    cout << "3 3" << endl;

    ll p = pow(2, 18) - 1;
    A[0][0] = A[1][0] = A[0][1] = A[2][1] = A[1][2] = p;
    A[2][2] = A[1][1] = K;
    A[0][2] = A[2][0] = (~K) & p;
    REP(i, 3) {
        REP(j, 3) {
            cout << A[i][j];
            if (j < 2)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}