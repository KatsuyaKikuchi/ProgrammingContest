#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[300005];
ll S[505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll ans = 0;
    memset(S, 0, sizeof(S));
    ll m = 250;
    REP(i, N) {
        ll a;
        cin >> a;
        REP(j, 500) {
            ll t = ((j-m) - a);
            ans += t * t * S[j];

        }
        S[a + m]++;
    }
    cout << ans << endl;
    return 0;
}