#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N);
    ll ans = INF;
    REP(i, N) {
        ll r = i + K - 1;
        if (r >= N)
            break;
        ans = std::min(abs(A[i] - A[r]), ans);
    }
    cout << ans << endl;
    return 0;
}