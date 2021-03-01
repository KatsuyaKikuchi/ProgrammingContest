#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> dp(N + 5, 0);
    ll ans = 0;
    REP(i, N) {
        ll p = std::max(0LL, A[i] - 1 - dp[i]);
        ans += p;
        ll cnt = p + dp[i];
        cnt -= std::max(0LL, i + A[i] - (N - 1));
        for (ll j = std::min(i + A[i], N - 1); j > i && cnt > 0; --j) {
            dp[j]++;
            cnt--;
        }
        dp[i + 1] += cnt;
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}