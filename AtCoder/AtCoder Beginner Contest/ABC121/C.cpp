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
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A + N, [](pll a, pll b) {
        return a.first < b.first;
    });

    ll ans = 0;
    REP(i, N) {
        ans += A[i].first * A[i].second;
        M -= A[i].second;
        if (M <= 0) {
            ans -= abs(M) * A[i].first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}