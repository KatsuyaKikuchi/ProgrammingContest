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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Z, W;
    cin >> N >> Z >> W;
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = abs(A[N - 1] - W);
    if (N >= 2) {
        ans = std::max(ans, abs(A[N - 1] - A[N - 2]));
    }
    cout << ans << endl;
    return 0;
}