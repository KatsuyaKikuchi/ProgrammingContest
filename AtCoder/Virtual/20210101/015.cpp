#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, T;
    cin >> N >> T;
    ll s = 0;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        s += A[i].first;
    }

    sort(A, A + N, [](pll a, pll b) { return a.first - a.second > b.first - b.second; });
    ll ans = 0;
    REP(i, N) {
        if (s <= T)
            break;
        s -= A[i].first - A[i].second;
        ans++;
    }

    if (s > T)
        ans = -1;
    cout << ans << endl;

    return 0;
}