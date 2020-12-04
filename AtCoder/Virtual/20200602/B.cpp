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
    ll A, B, C;
    cin >> A >> B >> C;
    ll mx = std::max({A, B, C});
    ll ans = 0;
    while (A + 2 <= mx) {
        ans++;
        A += 2;
    }
    while (B + 2 <= mx) {
        ans++;
        B += 2;
    }
    while (C + 2 <= mx) {
        ans++;
        C += 2;
    }

    ll n = 0;
    if (A != mx)
        n++;
    if (B != mx)
        n++;
    if (C != mx)
        n++;

    if (n == 1)
        ans += 2;
    if (n == 2)
        ans++;
    cout << ans << endl;
    return 0;
}