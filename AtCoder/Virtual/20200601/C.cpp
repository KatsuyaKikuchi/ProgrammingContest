#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll S = 0;
    REP(i, N) {
        cin >> A[i];
        S += A[i];
    }

    ll ans = INF;
    ll s = A[0];
    FOR(i, N, 1) {
        ll t = S - s;
        ans = std::min(ans, abs(t - s));
        s += A[i];
    }
    cout << ans << endl;
    return 0;
}