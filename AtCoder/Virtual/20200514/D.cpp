#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[15][15];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll ans = 0;
    memset(S, 0, sizeof(S));
    REP(i, N) {
        ll a = i + 1;
        ll s = a % 10;
        ll p = a % 10;
        while (a > 0) {
            p = a % 10;
            a /= 10;
        }
        S[p][s]++;
    }
    REP(i, N) {
        ll a = i + 1;
        ll s = a % 10;
        ll p = a % 10;
        while (a > 0) {
            p = a % 10;
            a /= 10;
        }
        ans += S[s][p];
    }
    cout << ans << endl;
    return 0;
}