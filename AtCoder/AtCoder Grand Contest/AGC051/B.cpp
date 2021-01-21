#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<pll> ans;
    ans.push_back(pll(0, 0));
    ans.push_back(pll(1, 0));
    ans.push_back(pll(0, 1));
    ll cnt0 = 3, cnt1 = 2;
    ll left = 1, up = 1;
    while (cnt0 < 10LL * cnt1) {
        cnt0 *= 3LL;
        cnt1 *= 2LL;
        ll leftOfs = left + up + 1;
        ll upOfs = up + left + 1;
        vector<pll> add;
        for (ll i = ans.size() - 1; i >= 0; --i) {
            pll a(ans[i].first + leftOfs, ans[i].second);
            pll b(ans[i].first, ans[i].second + upOfs);
            ans.push_back(a);
            ans.push_back(b);
            left = std::max(left, a.first);
            up = std::max(up, b.second);
        }
    }
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << INF - ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}