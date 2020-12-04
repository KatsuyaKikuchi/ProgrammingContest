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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> H[i];
    }
    {
        ll s = 1;
        L[0] = 1;
        FOR(i, N, 1) {
            if (H[i] < H[i - 1])
                s = 0;
            L[i] = ++s;
        }
    }
    ll ans = L[N - 1];
    {
        ll s = 1;
        for (ll i = N - 2; i >= 0; --i) {
            if (H[i] < H[i + 1])
                s = 0;
            ll r = ++s + L[i] - 1;
            ans = std::max(ans, r);
        }
    }
    cout << ans << endl;
    return 0;
}