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
    ll R, G, B, N;
    cin >> R >> G >> B >> N;

    ll ans = 0;
    REP(i, N + 1) {
        if (R * i > N)
            break;
        REP(j, N + 1) {
            if (R * i + G * j > N)
                break;

            ll s = R * i + G * j;
            if ((N - s) % B == 0)
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}