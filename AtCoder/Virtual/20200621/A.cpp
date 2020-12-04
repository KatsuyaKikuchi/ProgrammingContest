#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;

    ll mx[3] = {0, 0, 0};
    REP(i, N) {
        ll A[3];
        REP(j, 3) {
            cin >> A[j];
        }
        sort(A, A + 3);
        REP(j, 3) {
            mx[j] = std::max(mx[j], A[j]);
        }
    }

    ll ans = 1;
    REP(i, 3) {
        ans *= mx[i];
    }
    cout << ans << endl;
    return 0;
}