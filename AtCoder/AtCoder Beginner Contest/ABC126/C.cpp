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
    ll N, K;
    cin >> N >> K;
    double ans = 0;

    REP(i, N) {
        //! i+1が出る
        ll t = i + 1;
        double p = 1.0 / (double) N;
        while (t < K) {
            p *= 0.5;
            t *= 2LL;
        }
        ans += p;
    }

    cout << OF64 << ans << endl;
    return 0;
}