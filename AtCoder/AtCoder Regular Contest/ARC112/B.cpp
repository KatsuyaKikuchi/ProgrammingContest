#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 2e18 + 100LL;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll B, C;
    cin >> B >> C;
    ll ans = 1;
    if (B == 0) {
        ll c = std::max(0LL, C - 1);
        ans += (c / 2LL) * 2LL;
        if (C % 2 == 0 && C > 0)
            ans++;
    }
    else if (B >= 0) {
        vector<pll> range;
        {
            //! そのまま引いていく
            range.push_back(pll(B - (C / 2LL), B));
        }
        if (C >= 1) {
            //! 最初に-1倍して引く
            range.push_back(pll(-B - (std::max(C - 1, 0LL) / 2LL), -B));
        }
        if (C >= 1) {
            //! 引いてマイナス
            ll c = C - 1;
            range.push_back(pll(-B, -B + (c / 2LL)));
        }
        if (C >= 2) {
            //! Bよりでかいやつ
            C -= 2;
            range.push_back(pll(B, B + (C / 2LL)));
        }
#if false
        REP(i, range.size()) {
            cout << range[i].first << " " << range[i].second << endl;
        }
#endif
        ans = 0;
        sort(range.begin(), range.end(), [](pll a, pll b) { return a.first < b.first; });
        ll r = -INF;
        REP(i, range.size()) {
            r = std::max(r + 1, range[i].first);
            ans += std::max(0LL, range[i].second - r + 1);
            r = std::max(r, range[i].second);
        }
    }
    else {
        vector<pll> range;
        {
            //! そのまま引いていく
            range.push_back(pll(B - (C / 2LL), B));
        }
        if (C >= 1) {
            //! 最初に-1倍して引く
            range.push_back(pll(-B - (std::max(C - 1, 0LL) / 2LL), -B));
        }
        if (C >= 1) {
            //! 引いてマイナス
            ll c = C - 1;
            range.push_back(pll(-B, -B + (c / 2LL)));
        }
        if (C >= 2) {
            //! Bよりでかいやつ
            C -= 2;
            range.push_back(pll(B, B + (C / 2LL)));
        }
        ans = 0;
        sort(range.begin(), range.end(), [](pll a, pll b) { return a.first < b.first; });
        ll r = -INF;
        REP(i, range.size()) {
            r = std::max(r + 1, range[i].first);
            ans += std::max(0LL, range[i].second - r + 1);
            r = std::max(r, range[i].second);
        }
    }
    cout << ans << endl;
    return 0;
}