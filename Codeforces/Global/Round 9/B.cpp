#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[305][305];
ll x[4] = {1, 0, -1, 0};
ll y[4] = {0, 1, 0, -1};

void solve() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        REP(j, M) {
            cin >> A[i][j];
        }
    }

    REP(i, N) {
        REP(j, M) {
            ll s = 0;
            REP(n, 4) {
                ll nx = x[n] + i, ny = y[n] + j;
                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;
                s++;
            }

            if (s < A[i][j]) {
                cout << "NO" << endl;
                return;
            }
            A[i][j] = s;
        }
    }

    cout << "YES" << endl;
    REP(i, N) {
        REP(j, M) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}