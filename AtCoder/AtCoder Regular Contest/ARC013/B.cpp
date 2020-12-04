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
    ll N;
    cin >> N;
    ll ans[3] = {0, 0, 0};
    REP(i, N) {
        vector<ll> v(3);
        REP(j, 3) {
            cin >> v[j];
        }
        sort(v.begin(), v.end());
        REP(j, 3) {
            ans[j] = std::max(ans[j], v[j]);
        }
    }
    cout << ans[0] * ans[1] * ans[2] << endl;
    return 0;
}