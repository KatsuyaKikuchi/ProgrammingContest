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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<pll> v(N);
    REP(i, N) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](pll a, pll b) { return a.first < b.first; });

    REP(i, N) {
        K -= v[i].second;
        if (K <= 0) {
            cout << v[i].first << endl;
            break;
        }
    }
    return 0;
}