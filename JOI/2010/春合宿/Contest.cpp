#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[15];
ll A[1005];
pll B[1005][15];

int main() {
    ll N, M, T, X, Y;
    cin >> N >> M >> T >> X >> Y;
    REP(i, M) {
        cin >> P[i];
    }

    memset(A, 0, sizeof(A));
    REP(i, Y) {
        ll t, n, m;
        string s;
        cin >> t >> n >> m >> s;
        n--;
        m--;
        if (s == "open") {
            B[n][m].first = t;
        }
        else if (s == "correct") {
            A[n] += std::max(X, P[m] - (t - B[n][m].first) - 120 * B[n][m].second);
        }
        else {
            B[n][m].second++;
        }
    }
    REP(i, Y) {
    }

    REP(i, N) {
        cout << A[i] << endl;
    }
    return 0;
}