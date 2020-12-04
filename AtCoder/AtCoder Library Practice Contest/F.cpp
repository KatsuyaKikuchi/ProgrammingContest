#include <bits/stdc++.h>
#include "atcoder/all"

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }

    auto C = atcoder::convolution(A, B);
    REP(i, C.size()) {
        cout << C[i] << " ";
    }
    cout << endl;
    return 0;
}