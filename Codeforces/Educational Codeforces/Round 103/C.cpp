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
    vector<ll> A(N), B(N), C(N);
    REP(i, N) {
        cin >> C[i];
    }
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    ll ret = 0;
    ll len = -(C[0] - 1) + 2LL * abs(A[1] - B[1]);
    FOR(i, N, 1) {
        ll a = std::min(A[i], B[i]);
        ll b = std::max(A[i], B[i]);
        if (a == b)
            len = -(C[i - 1] - 1);
        len += 2LL + a - 1 + (C[i - 1] - b);
        len = std::max(len, b - a + 2LL);
        ret = std::max(ret, len + C[i] - 1);
        // cout << ret << endl;
    }
    return ret;
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