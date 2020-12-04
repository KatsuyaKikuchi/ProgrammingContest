#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
ll B[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, T;
    cin >> N >> M >> T;
    ll am = INF, bm = INF;
    REP(i, N) {
        cin >> A[i];
        am = std::min(am, A[i]);
    }
    REP(i, M) {
        cin >> B[i];
        bm = std::min(bm, B[i]);
    }

    ll ans = am + bm;
    REP(i, T) {
        ll x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        ans = std::min(ans, A[x] + B[y] - c);
    }
    cout << ans << endl;

    return 0;
}