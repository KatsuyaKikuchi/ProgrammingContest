#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[200005];
pll B[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        B[i].first = A[i].first - A[i].second;
        B[i].second = A[i].first + A[i].second;
    }

    ll ans = 0;
    {
        ll mx = B[0].first, mn = B[0].first;
        REP(i, N) {
            mx = std::max(B[i].first, mx);
            mn = std::min(mn, B[i].first);
        }
        ans = mx - mn;
    }
    {
        ll mx = B[0].second, mn = B[0].second;
        REP(i, N) {
            mx = std::max(B[i].second, mx);
            mn = std::min(mn, B[i].second);
        }
        ans = std::max(ans, mx - mn);
    }
    cout << ans << endl;
    return 0;
}