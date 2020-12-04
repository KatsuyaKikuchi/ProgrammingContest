#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e11;

pll calc(ll h, ll c, ll t, ll x) {
    return pll(abs((h + c) * x - 2 * x * t - c + t), 2 * x - 1);
}

ll solve() {
    ll H, C, T;
    cin >> H >> C >> T;
    ll ret = 2;
    pll mn(abs(H + C - 2 * T), 2);
    ll ok = INF, ng = 0;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if ((H + C) * mid - 2 * mid * T - C + T < 0)
            ok = mid;
        else
            ng = mid;
    }
    {
        pll p = calc(H, C, T, ok);
        if (p.first * mn.second < p.second * mn.first) {
            mn = p;
            ret = 2 * ok - 1;
        }
    }
    {
        pll p = calc(H, C, T, ok - 1);
        if (p.first * mn.second == p.second * mn.first) {
            ret = std::min(ret, 2 * (ok - 1) - 1);
        }
        else if (p.first * mn.second < p.second * mn.first) {
            mn = p;
            ret = 2 * (ok - 1) - 1;
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}