#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N, K;
    cin >> N >> K;
#if false
    vector<ll> A;
    REP(i, K) {
        A.push_back(i + 1);
    }
    REP(i, N - K) {
        A.push_back(K - i - 1);
    }
    REP(i, A.size()) {
        cout << A[i] << " ";
    }
    cout << endl;
#endif
    ll last = K - (N - K);
    vector<ll> P;
    FOR(i, last, 1) {
        P.push_back(i);
    }
    for (ll i = K; i >= last; --i) {
        P.push_back(i);
    }
    REP(i, K) {
        cout << P[i] << " ";
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