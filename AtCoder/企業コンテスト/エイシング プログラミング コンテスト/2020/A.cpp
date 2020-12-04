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
    ll L, R, D;
    cin >> L >> R >> D;
    ll ans = 0;
    FOR(i, R + 1, L) {
        if (i % D == 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}