#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp0[2];
ll dp1[2];

ll solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    dp0[0] = dp1[0] = -INF;
    dp0[1] = dp1[1] = 0;
    REP(i, N) {
        dp1[0] = std::max(dp0[0], dp0[1] + A[i]);
        dp1[1] = std::max(dp0[1], dp0[0] - A[i]);
        swap(dp0, dp1);
        //cout << dp0[0] << " " << dp0[1] << endl;
    }
    //cout << "--------------" << endl;
    return std::max(dp0[0], dp0[1]);
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