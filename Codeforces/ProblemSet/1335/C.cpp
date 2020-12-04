#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(vector<ll> &A) {
    ll N = A.size();
    vector<ll> B(N);
    REP(i, N) {
        B[i] = A[i];
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());

    vector<ll> C(A.size(), 0);
    REP(i, N) {
        ll index = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        C[index]++;
    }

    ll ret = 0;
    REP(i, C.size()) {
        ll n = C[i];
        ll m = C.size();

        ret = std::max({ret, std::min(n, m - 1), std::min(n - 1, m)});
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N;
        cin >> N;
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }
        cout << solve(A) << endl;
    }
    return 0;
}