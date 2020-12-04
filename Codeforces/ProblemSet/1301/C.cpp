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
    ll ret = N * (N + 1) / 2;

    ll n = N - M;
    ll m = n / (M + 1);
    ll k = n % (M + 1);

    ret -= k * (m + 1) * (m + 2) / 2 + (M + 1 - k) * (m + 1) * m / 2;
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