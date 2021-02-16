#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll s = 0;
    REP(i, N) {
        cin >> A[i];
        s += A[i];
    }
    ll ans = 0;
    if (s % 10 == 0) {
        REP(i, N) {
            ll t = s - A[i];
            if (t % 10 != 0)
                ans = std::max(ans, t);
        }
    }
    else {
        ans = s;
    }
    cout << ans << endl;
    return 0;
}