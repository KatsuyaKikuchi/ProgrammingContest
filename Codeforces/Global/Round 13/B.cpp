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
    ll N, U, V;
    cin >> N >> U >> V;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll d = 0;
    REP(i, N - 1) {
        d = std::max(d, abs(A[i] - A[i + 1]));
    }
    if (d > 1) {
        return 0;
    }
    if (d == 1) {
        return std::min(U, V);
    }

    return std::min(2LL * V, U + V);
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