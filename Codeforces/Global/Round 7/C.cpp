#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

ll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }

    ll b = N - K + 1;
    ll s = 0;
    for (ll i = b; i <= N; ++i) {
        s += i;
    }

    ll left = 0;
    REP(i, N) {
        if (A[i] >= b) {
            left = i;
            break;
        }
    }

    ll ans = 1;
    ll n = 0;
    FOR(i, N, left + 1) {
        if (A[i] >= b) {
            ans = (ans * (n + 1)) % MOD;
            n = 0;
            continue;
        }
        n++;
    }
    cout << s << " " << ans << endl;
    return 0;
}