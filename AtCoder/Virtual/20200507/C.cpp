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
    ll N, K;
    cin >> N >> K;
    double ans = 0;
    REP(n, N) {
        double t = 1.0 / N;
        ll m = n + 1;
        while (m < K) {
            m *= 2LL;
            t *= 0.5;
        }
        ans += t;
    }
    cout << OF64 << ans << endl;
    return 0;
}