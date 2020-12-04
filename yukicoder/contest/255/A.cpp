#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 2e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll V, T, P;
    cin >> V >> T >> P;
    ll ans = 0, ng = INF;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;

        ll t = mid;
        t -= P * V;
        t -= (mid + T - 1) / T;
        if ((mid + T - 1) % T == 0)
            t++;

        if (t > V)
            ng = mid;
        else
            ans = mid;
    }

    cout << ans << endl;
    return 0;
}