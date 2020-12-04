#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    REP(i, K) {
        A[N - 1] += A[N - 2 - i];
        A[N - 2 - i] = 0;
    }
    ll mx = 0;
    ll mn = INF;
    REP(i, N) {
        mx = std::max(mx, A[i]);
        mn = std::min(mn, A[i]);
    }
    return mx - mn;
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