#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MUL = 10000LL;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    double tX, tY, tR;
    cin >> tX >> tY >> tR;
    ll X = round(tX * MUL);
    ll Y = round(tY * MUL);
    ll R = round(tR * MUL);
    ll height = (Y + R) / MUL;
    ll bottom = (Y - R) / MUL;
    ll ans = 0;
    for (ll y = bottom; y <= height; ++y) {
        ll yy = (Y - y * MUL) * (Y - y * MUL);
        ll d = R * R - yy;
        if (d < 0)
            continue;
        ll s = (ll) sqrt(d) + 1;
        ll right = (s + X) / MUL - 1;
        ll left = (-s + X) / MUL + 1;
        while ((X - (right + 1) * MUL) * (X - (right + 1) * MUL) + yy <= R * R)
            right++;
        while ((X - (left - 1) * MUL) * (X - (left - 1) * MUL) + yy <= R * R)
            left--;
        ans += std::max(0LL, (right - left + 1));
    }
    cout << ans << endl;
    return 0;
}