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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    ll sum = 0;
    REP(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    if (sum % M != 0)
        return N;
    ll mn = -1;
    REP(i, N) {
        if (A[i] % M != 0)
            mn = std::max({mn, N - 1 - i, i});
    }
    return mn;
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