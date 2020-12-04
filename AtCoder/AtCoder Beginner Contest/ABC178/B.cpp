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
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    ll ans = A * C;
    ans = std::max(A * D, ans);
    ans = std::max(B * C, ans);
    ans = std::max(ans, B * D);

    if ((A <= 0 && 0 <= B) || (C <= 0 && 0 <= D)) {
        ans = std::max(0LL, ans);
    }

    cout << ans << endl;
    return 0;
}