#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(vector<ll> &A, ll M) {
    ll N = A.size();
    ll s = 0;
    REP(i, N) {
        s += A[i];
    }
    return std::min(s, M);
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N, M;
        cin >> N >> M;
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }
        cout << solve(A, M) << endl;
    }
    return 0;
}