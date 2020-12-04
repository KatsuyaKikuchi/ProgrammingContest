#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool A[100005];
ll dp[100015];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, L;
    cin >> N >> L;
    memset(A, 0, sizeof(A));
    REP(i, N) {
        ll x;
        cin >> x;
        A[x] = true;
    }
    ll T1, T2, T3;
    cin >> T1 >> T2 >> T3;
    REP(i, L + 10) {
        dp[i] = INF;
    }
    dp[0] = 0;

    REP(i, L) {
        {
            //! type 1
            ll t = dp[i] + T1;
            if (A[i + 1])
                t += T3;
            dp[i + 1] = std::min(dp[i + 1], t);
        }
        if (i > 0) {
            //! type 2
            ll t = dp[i - 1] + T1 + T2;
            if (A[i + 1])
                t += T3;
            dp[i + 1] = std::min(dp[i + 1], t);
        }
        if (i - 3 >= 0) {
            //! type 3
            ll t = dp[i - 3] + T1 + 3 * T2;
            if (A[i + 1])
                t += T3;
            dp[i + 1] = std::min(dp[i + 1], t);
        }
    }

    //! 飛び越えながらゴール
    {
        dp[L] = std::min(dp[L], dp[L - 1] + T1 / 2 + T2 / 2);
        dp[L] = std::min(dp[L], dp[L - 2] + T1 / 2 + T2 * 3 / 2);
        if (L >= 3)
            dp[L] = std::min(dp[L], dp[L - 3] + T1 / 2 + T2 * 5 / 2);
    }
    cout << dp[L] << endl;
    return 0;
}