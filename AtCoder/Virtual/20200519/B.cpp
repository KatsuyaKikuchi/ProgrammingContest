#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[2][105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, 2) {
        REP(j, N) {
            cin >> A[i][j];
        }
    }
    ll s = 0;
    ll ans = 0;
    REP(i, N) {
        s += A[0][i];
        ll t = s;
        FOR(j, N, i) {
            t += A[1][j];
        }
        ans = std::max(t, ans);
    }
    cout << ans << endl;
    return 0;
}