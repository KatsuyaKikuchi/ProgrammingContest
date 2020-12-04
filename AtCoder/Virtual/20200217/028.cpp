#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[2005];

int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    REP(i, N) {
        cin >> A[i];
    }
    if (N == 1)
        cout << abs(A[0] - Y) << endl;
    else
        cout << std::max(abs(A[N - 1] - A[N - 2]),
                         abs(A[N - 1] - Y)) << endl;
    return 0;
}