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
    ll N;
    cin >> N;
    vector<vector<pll>> v(N);
    REP(i, N) {
        ll n;
        cin >> n;
        REP(j, n) {
            pll t;
            cin >> t.first >> t.second;
            t.first--;
            v[i].push_back(t);
        }
    }

    ll ans = 0;
    REP(bit, pow(2, N)) {
        bool enable = true;
        ll count = 0;
        REP(j, N) {
            if ((bit >> j) & 1) {
                count++;
                REP(k, v[j].size()) {
                    if (((bit >> v[j][k].first) & 1) != v[j][k].second)
                        enable = false;
                }
            }
        }
        if (enable) {
            ans = std::max(ans, count);
        }
    }
    cout << ans << endl;

    return 0;
}