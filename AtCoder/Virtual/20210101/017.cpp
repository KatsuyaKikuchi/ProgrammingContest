#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll ans = 0;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    for (ll i = N - 1; i >= 0; --i) {
        ll a = A[i].first + ans;
        ll b = A[i].second;
        a %= b;
        ans += (b - a) % b;
    }
    cout << ans << endl;
    return 0;
}