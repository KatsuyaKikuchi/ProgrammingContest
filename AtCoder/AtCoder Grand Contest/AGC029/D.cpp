#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A + N, [](pll a, pll b) { return a.first == b.first ? a.second < b.second : a.first < b.first; });
    pll p(1, 1);
    ll ans = H;
    REP(i, N) {
        pll g = A[i];
        ll dx = g.second - p.second;
        ll y = p.first + dx;
        if (g.first < y)
            continue;
        else if (g.first > y) {
            ans = std::min(ans, g.first - 1);
            continue;
        }
        p = pll(g.first, g.second - 1);
    }

    cout << ans << endl;
    return 0;
}