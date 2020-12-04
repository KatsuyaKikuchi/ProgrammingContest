#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H[300005];
ll L[300005];
ll R[300005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> H[i];
    }
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    {
        ll s = 0;
        REP(i, N) {
            if (i > 0 && H[i - 1] >= H[i])
                s = 0;
            L[i] = ++s;
        }
    }
    {
        ll s = 0;
        for (ll i = N - 1; i >= 0; --i) {
            if (i < N - 1 && H[i + 1] >= H[i])
                s = 0;
            R[i] = ++s;
        }
    }

    ll ans = 0;
    REP(i, N) {
        ans = std::max(ans, L[i] + R[i] - 1);
    }
    cout << ans << endl;
    return 0;
}