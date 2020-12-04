#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K, N;
    cin >> K >> N;
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = K;
    REP(i, N - 1) {
        ans = std::min(ans, K - abs(A[i + 1] - A[i]));
    }

    ans = std::min(ans, K - abs(K - A[N - 1] + A[0]));
    cout << ans << endl;
    return 0;
}