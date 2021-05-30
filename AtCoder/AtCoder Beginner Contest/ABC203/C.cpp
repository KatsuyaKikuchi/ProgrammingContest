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
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end(), [](pll a, pll b) { return a.first < b.first; });
    ll ans = 0;
    REP(i, N) {
        if (ans + K < A[i].first) {
            ans += K;
            K = 0;
            break;
        }
        K -= A[i].first - ans;
        ans = A[i].first;
        K += A[i].second;
    }
    cout << ans + K << endl;
    return 0;
}