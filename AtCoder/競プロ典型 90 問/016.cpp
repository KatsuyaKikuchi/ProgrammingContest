#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    ll ans = INF;
    ll MAX = 10000;
    REP(a, MAX) {
        REP(b, MAX - a) {
            ll n = N - a * A - b * B;
            if (n < 0)
                break;
            if (n % C != 0)
                continue;
            ll c = n / C;
            ans = std::min(a + b + c, ans);
        }
    }
    cout << ans << endl;
    return 0;
}