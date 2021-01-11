#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, C;
    cin >> N >> C;
    vector<pll> A;
    REP(i, N) {
        ll a, b, c;
        cin >> a >> b >> c;
        A.push_back(pll(a, c));
        A.push_back(pll(b + 1, -c));
    }
    A.push_back(pll(INF, 0));
    sort(A.begin(), A.end(), [](pll a, pll b) { return a.first < b.first; });
    ll x = 0;
    ll t = 0;
    ll ans = 0;
    ll idx = 0;
    while (idx < A.size()) {
        ans += std::min(x, C) * (A[idx].first - t);
        t = A[idx].first;
        while (idx < A.size() && A[idx].first == t) {
            x += A[idx].second;
            idx++;
        }
    }
    cout << ans << endl;
    return 0;
}