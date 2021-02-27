#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 4e18;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

long long gcd(long long a, long long b) {
    if (a < b)
        swap(a, b);
    long long c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

//! 方程式 ax = b (mod m) の解xを返す。
//! 見つからなかった場合 -1
long long mod_solver(long long a, long long b, long long m) {
    if (a < 0) {
        a = (m - (abs(a) % m)) % m;
    }
    if (b < 0) {
        b = (m - (abs(b) % m)) % m;
    }
    a %= m;
    b %= m;
    if (b == 0)
        return 0;
    if (a == 0)
        return -1;
    long long g0 = gcd(m, gcd(a, b));
    a /= g0;
    b /= g0;
    m /= g0;
    long long x, y;
    long long g1 = extGCD(a, m, x, y);
    if (g1 != 1) {
        return -1;
    }
    if (x < 0)
        x += m;
    return (x * b) % m;
}

ll solve() {
    ll X, Y, P, Q;
    cin >> X >> Y >> P >> Q;

    ll ret = INF;
    for (ll x = -Q + 1; x < Y; ++x) {
        // 電車から見た相対位置がxとなるような最小値
        //! 2*(X+Y)*t +X +x == P (mod P+Q)
        ll t = mod_solver(2LL * (X + Y), P - X - x, P + Q);
        if (t < 0)
            continue;
        ll ans = 2LL * (X + Y) * t + X;
        if (x >= 0) {
            ans += x;
        }
        ret = std::min(ret, ans);
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
        ll ans = solve();
        if (ans < 0) {
            cout << "infinity" << endl;
        }
        else {
            cout << ans << endl;
        }
    }
    return 0;
}