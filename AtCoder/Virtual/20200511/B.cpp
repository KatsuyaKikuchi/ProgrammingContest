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
    ll M = std::max({A, B, C});
    ll ans = (M - A) / 2 + (M - B) / 2 + (M - C) / 2;
    ll odd = (M - A) % 2 + (M - B) % 2 + (M - C) % 2;
    if (odd == 1)
        ans += 2;
    else if (odd == 2)
        ans++;

    cout << ans << endl;
    return 0;
}