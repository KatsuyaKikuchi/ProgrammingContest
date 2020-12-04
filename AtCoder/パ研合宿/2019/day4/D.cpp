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
    ll N, X;
    cin >> N >> X;
    REP(i, N + 1) {
        ll n = i + 1;
        ll s = n * (n + 1) / 2;
        if (X > s)
            continue;

        //! 前からn個を1,n+1個目をn-(X-s)とす 14
        vector<ll> ans(N, (ll) 1e9);
        ll k = i;
        REP(j, k) {
            ans[j] = 1;
        }
        ans[k] = k - (X - i * (i + 1) / 2) + 1;

        cout << k << endl;
        REP(j, N) {
            cout << ans[j] << " ";
        }
        cout << endl;
        break;
    }

    return 0;
}