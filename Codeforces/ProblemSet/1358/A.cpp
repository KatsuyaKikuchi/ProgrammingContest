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
    ll ret = std::min(((N + 1) / 2) * M, ((M + 1) / 2) * N);
    if (N > 1 && M > 1 && N % 2 == 1 && M % 2 == 1)
        ret = std::min((N / 2) * M + (M + 1) / 2, (M / 2) * N + (N + 1) / 2);
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        cout << solve() << endl;
    }
    return 0;
}