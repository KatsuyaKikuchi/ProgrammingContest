#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll ans = 0;
    REP(i, N) {
        ll a, b;
        cin >> a >> b;
        ll s = (b + 1) * b / 2;
        s -= (a - 1) * a / 2;
        ans += s;
    }
    cout << ans << endl;
    return 0;
}