#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    ll mx = -INF;
    REP(i, N) {
        mx = std::max(A[i], mx);
    }
    REP(i, N) {
        A[i] = mx - A[i];
    }

    if (K % 2 == 0) {
        mx = -INF;
        REP(i, N) {
            mx = std::max(A[i], mx);
        }
        REP(i, N) {
            A[i] = mx - A[i];
        }
    }
    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}