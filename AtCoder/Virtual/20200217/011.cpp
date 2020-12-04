#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll N;
    cin >> N;
    vector<pll> v;
    REP(i, N) {
        ll x, l;
        cin >> x >> l;
        v.push_back(pll(x - l, x + l));
    }
    sort(v.begin(), v.end(), [](pll a, pll b) { return a.second < b.second; });
    ll ans = 0;
    ll right = -INF;
    REP(i, N) {
        if (right > v[i].first)
            continue;
        ans++;
        right = v[i].second;
    }
    cout << ans << endl;
    return 0;
}