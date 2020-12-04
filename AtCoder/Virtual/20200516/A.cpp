#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool U[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, K) {
        ll d;
        cin >> d;
        REP(j, d) {
            ll a;
            cin >> a;
            U[a - 1] = true;
        }
    }
    ll ans = 0;
    REP(i, N) {
        if (!U[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}