#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[5][5];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 3) {
        REP(j, 3) {
            cin >> C[i][j];
        }
    }

    for (ll a1 = -100; a1 <= 200; a1++) {
        ll b1 = C[0][0] - a1;
        ll b2 = C[0][1] - a1;
        ll b3 = C[0][2] - a1;
        ll a2 = C[1][0] - b1;
        ll a3 = C[2][0] - b1;
        ll A[3] = {a1, a2, a3};
        ll B[3] = {b1, b2, b3};

        bool e = true;
        REP(i, 3) {
            REP(j, 3) {
                if (A[i] + B[j] != C[i][j])
                    e = false;
            }
        }
        if (e) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}