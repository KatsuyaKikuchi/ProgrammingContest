#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll cnt = 100000;
    map<pll, bool> mp;
    for (ll n = 2; n <= 10000; n += 2) {
        for (ll m = 1; m <= 10000; m += 2) {
            ll a = abs(m * m - n * n);
            ll b = 2LL * n * m;
            ll c = m * m + n * n;
            ll aa = std::min({a, b, c});
            ll cc = std::max({a, b, c});
            ll bb = a + b + c - aa - cc;
            ll g = gcd(gcd(aa, bb), cc);
            if (g != 1)
                continue;
            if (mp[pll(aa, bb)])
                continue;
            mp[pll(aa, bb)] = true;
            cout << aa << " " << bb << " " << cc << endl;
            cnt--;
            if (cnt == 0) {
                //cout << "OK!" << endl;
                return 0;
            }
        }
    }
    return 0;
}