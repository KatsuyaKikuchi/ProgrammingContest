#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[300005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, 3 * N) {
        cin >> A[i];
    }
    sort(A, A + 3 * N, greater<ll>());

    ll ans = 0;
    REP(i, N) {
        ans += A[2 * i + 1];
    }
    cout << ans << endl;
    return 0;
}