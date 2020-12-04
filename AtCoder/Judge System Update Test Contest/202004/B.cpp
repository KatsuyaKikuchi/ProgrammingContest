#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll X[105];
char C[105];
bool U[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> X[i] >> C[i];
    }

    REP(i, N) {
        ll ri = -1, bi = -1;
        REP(j, N) {
            if (U[j])
                continue;
            if (C[j] == 'R' && (ri < 0 || X[ri] > X[j]))
                ri = j;
            if (C[j] == 'B' && (bi < 0 || X[bi] > X[j]))
                bi = j;
        }

        if (ri >= 0) {
            cout << X[ri] << endl;
            U[ri] = true;
        }
        else {
            cout << X[bi] << endl;
            U[bi] = true;
        }
    }
    return 0;
}