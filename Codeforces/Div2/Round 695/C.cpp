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
    vector<ll> N(3);
    REP(i, 3) {
        cin >> N[i];
    }
    vector<vector<ll>> A(3, vector<ll>());
    REP(i, 3) {
        REP(_, N[i]) {
            ll a;
            cin >> a;
            A[i].push_back(a);
        }
    }
    vector<ll> S(3, 0);
    REP(i, 3) {
        sort(A[i].begin(), A[i].end());
        REP(j, N[i]) {
            S[i] += A[i][j];
        }
    }
    ll s = S[0] + S[1] + S[2];
    ll m = A[0][0] + A[1][0] + A[2][0];
    ll ans = -INF;
    REP(i, 3) {
        ans = std::max(ans, s - S[i] * 2LL);
        ans = std::max(ans, s - 2LL * m + 2LL * A[i][0]);
    }
    cout << ans << endl;
    return 0;
}