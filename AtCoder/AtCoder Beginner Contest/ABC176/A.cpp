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
    ll N, X, T;
    cin >> N >> X >> T;
    ll ans = 0;
    ll num = 0;
    while (num < N) {
        num += X;
        ans += T;
    }
    cout << ans << endl;
    return 0;
}