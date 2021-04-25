#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[2005][2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }

    vector<ll> SH(H, 0), SW(W, 0);
    REP(i, H) {
        REP(j, W) {
            SH[i] += A[i][j];
            SW[j] += A[i][j];
        }
    }

    REP(i, H) {
        REP(j, W) {
            cout << SH[i] + SW[j] - A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}