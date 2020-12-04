#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
        REP(j, 40) {
            ll a = ((~0LL) << j) & A[i];
            if (a > 0)
                A[i] = a;
        }
    }
    if (N == 1)
        return 0;
    sort(A.begin(), A.end());
    vector<ll> B(N);
    REP(i, N) {
        B[i] = A[i];
    }
    B.erase(unique(B.begin(), B.end()), B.end());
    vector<ll> C(B.size() + 1, 0);
    ll ret = N * (N - 1) / 2;
    REP(i, N) {
        ll index = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        C[index + 1]++;
    }
    REP(i, C.size() - 1) {
        C[i + 1] += C[i];
    }
    REP(i, N) {
        ll index = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        ret -= C[index];
    }
    return ret;
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