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
    ll H, W;
    cin >> H >> W;
    ll ans = INF;
    REP(i, H - 1) {
        ll a = W * (i + 1);
        ll h = H - (i + 1);
        {
            ll w = W / 2;
            ll b = h * w;
            ll c = h * (W - w);
            ans = std::min(ans, std::max({a, b, c}) - std::min({a, b, c}));
        }
        {
            ll hh = h / 2;
            ll b = hh * W;
            ll c = (h - hh) * W;
            ans = std::min(ans, std::max({a, b, c}) - std::min({a, b, c}));
        }
    }
    REP(i, W - 1) {
        ll a = H * (i + 1);
        ll w = W - (i + 1);
        {
            ll h = H / 2;
            ll b = h * w;
            ll c = (H - h) * w;
            ans = std::min(ans, std::max({a, b, c}) - std::min({a, b, c}));
        }
        {
            ll ww = w / 2;
            ll b = ww * H;
            ll c = (w - ww) * H;
            ans = std::min(ans, std::max({a, b, c}) - std::min({a, b, c}));
        }
    }
    cout << ans << endl;
    return 0;
}