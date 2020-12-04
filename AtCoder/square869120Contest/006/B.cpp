#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e10;

ll N;
pll A[35];

int main() {
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A + N, [](pll a, pll b) { return a.first < b.first; });
    ll s = A[N / 2].first;
    sort(A, A + N, [](pll a, pll b) { return a.second < b.second; });
    ll g = A[N / 2].second;
    ll ans = 0;
    REP(i, N) {
        ans += abs(A[i].first - A[i].second);
        ans += abs(s - A[i].first);
        ans += abs(g - A[i].second);
    }
    cout << ans << endl;
    return 0;
}