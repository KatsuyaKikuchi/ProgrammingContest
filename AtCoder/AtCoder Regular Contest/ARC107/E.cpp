#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H[500005], W[500005];

ll mex(ll a, ll b) {
    if (a == 0) {
        if (b == 1)
            return 2;
        return 1;
    }
    else if (a == 1) {
        if (b == 0)
            return 2;
        return 0;
    }
    if (b == 0)
        return 1;
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    REP(i, N) {
        cin >> W[i];
    }
    REP(i, N - 1) {
        cin >> H[i + 1];
    }
    vector<vector<ll>> A(N, vector<ll>(N, 0));
    REP(i, N) {
        A[0][i] = W[i];
    }
    REP(i, N - 1) {
        A[i + 1][0] = H[i + 1];
    }
    REP(i, N - 1) {
        REP(j, N - 1) {
            A[i + 1][j + 1] = mex(A[i][j + 1], A[i + 1][j]);
        }
    }
    REP(i, N) {
        REP(j, N) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}