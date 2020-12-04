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
    ll N, T;
    cin >> N >> T;
    ll ans = INF;
    REP(i, N) {
        ll c, t;
        cin >> c >> t;
        if (t <= T)
            ans = std::min(ans, c);
    }

    if (ans == INF)
        cout << "TLE" << endl;
    else
        cout << ans << endl;
    return 0;
}