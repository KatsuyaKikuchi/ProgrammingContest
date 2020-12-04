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
    REP(i, M) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A + M, [](pll a, pll b) { return a.second < b.second; });
    ll ans = 0;
    ll right = -INF;
    REP(i, M) {
        if (right > A[i].first)
            continue;
        ans++;
        right = A[i].second;
    }
    cout << ans << endl;
    return 0;
}