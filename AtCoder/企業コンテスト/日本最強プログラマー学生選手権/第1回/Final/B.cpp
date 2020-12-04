#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string A[305], B[305];
bool U[305][305];

char C[305][305];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    memset(U, 0, sizeof(U));

    REP(i, N) {
        REP(j, N) {
            if (A[i][j] == '0')
                continue;
            REP(k, N) {
                if (B[i][k] == '0')
                    U[j][k] = true;
            }
        }
    }

    REP(i, N) {
        REP(j, N) {
            C[i][j] = '0';
        }
    }
    REP(i, N) {
        REP(j, N) {
            if (B[i][j] == '0')
                continue;
            bool exist = false;
            REP(k, N) {
                if (A[i][k] == '1' && !U[k][j]) {
                    C[k][j] = '1';
                    exist = true;
                    break;
                }
            }

            if (!exist) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    REP(i, N) {
        REP(j, N) {
            cout << C[i][j];
        }
        cout << endl;
    }
    return 0;
}