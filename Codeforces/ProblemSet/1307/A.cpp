#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(ll N, ll D, vector<ll> &A) {
    REP(i, D) {
        FOR(i, N, 1) {
            if (A[i] > 0) {
                A[i - 1]++;
                A[i]--;
                break;
            }
        }
    }
    return A[0];
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N, D;
        cin >> N >> D;
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }
        cout << solve(N, D, A) << endl;
    }
    return 0;
}