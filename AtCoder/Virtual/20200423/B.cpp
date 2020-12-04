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
    ll m = std::max({A, B, C});

    ll ans = 0;
    ans += (m - A) / 2 + (m - B) / 2 + (m - C) / 2;
    A += ((m - A) / 2) * 2;
    B += ((m - B) / 2) * 2;
    C += ((m - C) / 2) * 2;

    ll s = (m - A) + (m - B) + (m - C);
    if (s == 1)
        ans += 2;
    else if (s == 2)
        ans++;
    cout << ans << endl;
    return 0;
}