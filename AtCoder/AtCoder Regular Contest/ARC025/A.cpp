#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 7) {
        cin >> A[i].first;
    }
    REP(i, 7) {
        cin >> A[i].second;
    }
    ll ans = 0;
    REP(i, 7) {
        ans += std::max(A[i].first, A[i].second);
    }
    cout << ans << endl;
    return 0;
}