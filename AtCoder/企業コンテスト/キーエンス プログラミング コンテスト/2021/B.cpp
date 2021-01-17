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
    vector<ll> A(N, 0);
    REP(i, N) {
        ll a;
        cin >> a;
        A[a]++;
    }
    ll n = K;
    ll ans = 0;
    REP(i, N) {
        ll m = std::min(n, A[i]);
        ans += i * (n - m);
        n = m;
    }
    cout << ans << endl;
    return 0;
}