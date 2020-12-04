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
    ll A, B, C, K;
    cin >> A >> B >> C >> K;

    ll ans = 0;
    ll a = std::min(A, K);
    K -= a;
    ll b = std::min(B, K);
    K -= b;
    ll c = std::min(C, K);
    ans = a - c;
    cout << ans << endl;
    return 0;
}