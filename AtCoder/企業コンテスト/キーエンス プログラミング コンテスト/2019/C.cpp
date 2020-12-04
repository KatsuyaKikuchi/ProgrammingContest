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
    ll s0 = 0, s1 = 0;
    REP(i, N) {
        cin >> A[i].first;
        s0 += A[i].first;
    }
    REP(i, N) {
        cin >> A[i].second;
        s1 += A[i].second;
    }
    if (s0 < s1) {
        cout << -1 << endl;
        return 0;
    }

    sort(A, A + N, [](pll a, pll b) { return a.first - a.second > b.first - b.second; });
    ll m = 0;
    ll ans = 0;
    REP(i, N) {
        if (A[i].first - A[i].second < 0) {
            m += A[i].second - A[i].first;
            ans++;
        }
    }

    REP(i, N) {
        if (A[i].first - A[i].second < 0)
            break;
        if (m <= 0)
            break;
        m -= A[i].first - A[i].second;
        ans++;
    }

    cout << ans << endl;
    return 0;
}