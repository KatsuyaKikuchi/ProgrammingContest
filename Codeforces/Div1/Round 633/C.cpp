#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

typedef ll i;
#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll T[4][3] = {{0, 0, 0},
              {1, 2, 3},
              {2, 3, 1},
              {3, 1, 2}};

ll solve(ll N) {
    if (N <= 3) {
        return N;
    }
    ll p = 1;
    while (p * 4LL <= N) {
        p *= 4LL;
    }

    ll m = N % 3;
    if (m == 0)
        m = 3;
    ll ret = m * p;
    N -= p;
    p = 1;
    ll q = 3;
    while (N >= q) {
        ll a = N % 3;
        ll b = (N / q) % 4;
        ret += p * T[b][a];
        p *= 4LL;
        q *= 4LL;
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
        cout << solve(N) << endl;
    }
    return 0;
}