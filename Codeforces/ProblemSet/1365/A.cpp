#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[55][55];

string solve() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        REP(j, M) {
            cin >> A[i][j];
        }
    }

    ll r = N, c = M;
    REP(i, N) {
        REP(j, M) {
            if (A[i][j] == 1) {
                r--;
                break;
            }
        }
    }
    REP(j, M) {
        REP(i, N) {
            if (A[i][j] == 1) {
                c--;
                break;
            }
        }
    }

    if (std::min(r, c) % 2 == 0)
        return "Vivek";
    return "Ashish";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}