#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[105][105];
bool U[105];

void solve(ll N) {
    ll s = 0;

    REP(i, N) {
        s += A[i][i];
    }

    ll r = 0;
    REP(i, N) {
        memset(U, 0, sizeof(U));
        REP(j, N) {
            if (U[A[i][j]]) {
                r++;
                break;
            }
            U[A[i][j]] = true;
        }
    }

    ll c = 0;
    REP(i, N) {
        memset(U, 0, sizeof(U));
        REP(j, N) {
            if (U[A[j][i]]) {
                c++;
                break;
            }
            U[A[j][i]] = true;
        }
    }
    cout << s << " " << r << " " << c << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N;
        cin >> N;
        REP(i, N) {
            REP(j, N) {
                cin >> A[i][j];
            }
        }
        cout << "Case #" << _ + 1 << ": ";
        solve(N);
    }
    return 0;
}