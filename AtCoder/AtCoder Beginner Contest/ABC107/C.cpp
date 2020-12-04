#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

ll calc(ll a, ll b) {
    if (b <= 0)
        return abs(a);
    if (a >= 0)
        return abs(b);
    ll len = b - a;
    return std::min(abs(a) + len, abs(b) + len);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = INF;
    REP(i, N) {
        ll last = i + K - 1;
        if (last >= N)
            break;
        ll x0 = A[i];
        ll x1 = A[last];

        ll cost = calc(x0, x1);
        ans = std::min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}