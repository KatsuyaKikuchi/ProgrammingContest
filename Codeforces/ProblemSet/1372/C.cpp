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
    }

    ll left = -1, right = N;
    REP(i, N) {
        if (A[i] != i + 1)
            break;
        left = i;
    }
    for (ll i = N - 1; i >= 0; --i) {
        if (A[i] != i + 1)
            break;
        right = i;
    }

    if (left > right)
        return 0;

    FOR(i, right, left + 1) {
        if (A[i] == i + 1)
            return 2;
    }
    return 1;
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