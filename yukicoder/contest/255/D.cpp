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
ll B[100005];

//! 社員iの声がサーバーにアップされる時間
ll C[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    C[0] = A[0];
    C[1] = A[0] + B[1] + A[1];
    FOR(i, N, 2) {
        C[i] = std::min(C[i - 1] + A[i] + B[i], C[i - 2] + A[i] + B[i] + K);
    }

    ll ans = 0;
    REP(i, N) {
        ans = std::max(ans, C[i] - A[i]);
    }

    cout << ans << endl;
    return 0;
}