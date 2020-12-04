#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[100005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    A[N] = pll(0, 0);

    sort(A, A + N + 1, [](pll a, pll b) { return a.first > b.first; });

    ll ans = std::max(A[0].first, A[0].second);
    FOR(i, N + 1, 1) {
        ans = std::max(ans + A[i - 1].first - A[i].first, A[i].second);
    }
    cout << ans << endl;
    return 0;
}