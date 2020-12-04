#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(ll X, vector<ll> &A) {
    ll max = 0;
    REP(i, A.size()) {
        if (A[i] == X)
            return 1;
        max = std::max(max, A[i]);
    }
    if (max > X)
        return 2;
    return (X + max - 1) / max;
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N, X;
        cin >> N >> X;
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }

        cout << solve(X, A) << endl;
    }
    return 0;
}