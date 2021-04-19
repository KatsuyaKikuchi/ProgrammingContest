#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[505][505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        REP(j, N) {
            cin >> C[i][j];
        }
    }

    bool exist = true;
    vector<ll> A(N, 0), B(N, 0);

    vector<vector<pll>> G(N);
    REP(j, N) {
        ll p = C[0][(j + 1) % N] - C[0][j];
        REP(i, N) {
            ll x = C[i][(j + 1) % N] - C[i][j];
            if (p != x) {
                exist = false;
            }
        }
        if (j == N - 1) {
            if (A[j] + p != 0) {
                exist = false;
            }
        }
        A[(j + 1) % N] = A[j] + p;
    }

    ll mn = INF;
    REP(i, N) {
        mn = std::min(mn, A[i]);
    }
    REP(i, N) {
        A[i] += -mn;
    }

    REP(i, N) {
        B[i] = C[i][0] - A[0];
        if (B[i] < 0)
            exist = false;
    }

    if (exist) {
        cout << "Yes" << endl;
        REP(i, N) {
            cout << B[i] << " ";
        }
        cout << endl;
        REP(i, N) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}