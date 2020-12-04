#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
ll X[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    REP(i, N) {
        cin >> A[i];
    }
    memset(X, 0, sizeof(X));
    REP(i, N) {
        X[i + 1] = X[i] ^ A[i];
    }

    REP(i, Q) {
        ll l, r;
        cin >> l >> r;
        cout << (X[r] ^ X[l - 1]) << endl;
    }

    return 0;
}