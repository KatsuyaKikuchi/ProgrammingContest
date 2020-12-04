#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

ll calc(ll s, ll num, ll x) {
    vector<ll> v;
    v.push_back(s);
    REP(i, num) {
        v.push_back(9);
    }
    ll d = std::min(x, 8LL);
    v.push_back(d);
    x -= d;
    while (x > 0) {
        ll t = std::min(x, 9LL);
        v.push_back(t);
        x -= t;
    }
    ll ret = 0;
    reverse(v.begin(), v.end());
    REP(i, v.size()) {
        ret = ret * 10LL + v[i];
    }
    return ret;
}

ll solve() {
    ll N, K;
    cin >> N >> K;
    K++;
    ll ret = INF;
    REP(i, 10) {
        ll s = 0;
        ll p = 0;
        REP(j, K) {
            s += (i + j) % 10;
            if ((i + j) % 10 < i)
                p++;
        }
        if (s > N)
            continue;
        REP(j, 20) {
            //! 9をj個使う
            ll t = 9 * j * (K - p) + s;
            ll d = (N - t) - p;
            if (d < 0 || d % K != 0)
                continue;
            ll x = d / K;
            ret = std::min(ret, calc(i, j, x));
        }
    }
    if (ret == INF)
        ret = -1;
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