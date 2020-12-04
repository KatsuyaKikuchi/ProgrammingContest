#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(vector<ll> &A, ll X) {
    sort(A.begin(), A.end(), greater<>());

    ll N = A.size();
    ll s = 0;
    REP(i, N) {
        s += A[i];
        if (s < X * (i + 1))
            return i;
    }
    return N;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N, X;
        cin >> N >> X;
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }
        cout << solve(A, X) << endl;
    }
    return 0;
}