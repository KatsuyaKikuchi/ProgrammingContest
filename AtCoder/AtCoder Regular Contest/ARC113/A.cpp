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

    ll N;
    cin >> N;
    ll ans = 0;
    FOR(a, N + 1, 1) {
        FOR(b, N + 1, 1) {
            ll t = a * b;
            if (t > N)
                break;
            FOR(c, N + 1, 1) {
                ll x = t * c;
                if (x > N)
                    break;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}