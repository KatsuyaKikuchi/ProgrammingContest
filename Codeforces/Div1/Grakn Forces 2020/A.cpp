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
    ll N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    REP(i, N) {
        cin >> C[i];
    }
    vector<ll> P(N, -1);
    P[0] = A[0];
    FOR(i, N, 1) {
        P[i] = A[i];
        if (P[i] == P[i - 1] || P[i] == P[(i + 1) % N]) {
            P[i] = B[i];
        }
        if (P[i] == P[i - 1] || P[i] == P[(i + 1) % N]) {
            P[i] = C[i];
        }
    }
    REP(i, N) {
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