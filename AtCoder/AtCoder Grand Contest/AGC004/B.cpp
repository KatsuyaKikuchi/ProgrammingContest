#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[2005];
ll B[2005][2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X;
    cin >> N >> X;
    ll ans = 0;
    REP(i, N) {
        cin >> A[i];
        ans += A[i];
        B[i][0] = A[i];
    }
    REP(j, N) {
        REP(i, N) {
            B[i][j + 1] = std::min(B[i][j], A[(i - j - 1 + N) % N]);
        }
    }
    REP(i, N) {
        //! 魔法をi+1回使う
        ll n = i + 1;
        ll sum = n * X;
        REP(j, N) {
            sum += B[j][n];
        }
        ans = std::min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}