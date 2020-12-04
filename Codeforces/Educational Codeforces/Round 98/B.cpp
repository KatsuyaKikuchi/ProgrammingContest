#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll diff(ll m, ll n) {
    return ((n - 1) - (m % (n - 1))) % (n - 1);
}

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    REP(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    sort(A.begin(), A.end());
    ll ret = std::max({
                              diff(sum, N),
                              diff(A[N - 1] * (N - 1), N) + (A[N - 1] * (N - 1) - sum),
                              diff(A[N - 2] * (N - 1), N) + (A[N - 2] * (N - 1) - sum)});

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