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
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = 0;
#if true
    ll s = 0;
    ll index = 0;
    REP(i, N) {
        if ((s & A[i]) != 0) {
            ll n = 0;
            while ((s & A[i]) != 0) {
                ans += i - index;
                s ^= A[index++];
                n++;
            }
        }
        s ^= A[i];
    }
    ll m = N - index;
    ans += m * (m + 1) / 2;
#endif

    cout << ans << endl;
    return 0;
}