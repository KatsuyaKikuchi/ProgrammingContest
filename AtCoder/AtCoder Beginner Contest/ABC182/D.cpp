#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    ll mx = -INF;
    ll ans = 0;
    ll x = 0;
    ll dif = 0;
    REP(i, N) {
        dif += A[i];
        mx = std::max(mx, dif);
        ans = std::max(ans, x + mx);
        x += dif;
    }

    cout << ans << endl;
    return 0;
}