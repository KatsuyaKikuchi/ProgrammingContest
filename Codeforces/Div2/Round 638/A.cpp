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

    ll s0 = 0, s1 = 0;
    REP(i, N / 2 - 1) {
        s0 += pow(2, i + 1);
    }
    s0 += pow(2LL, N);
    s1 = pow(2LL, N + 1) - 2 - s0;

    return abs(s0 - s1);
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