#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll calcB(ll b) {
    b = (b * 10) / 6;
    //cout << b << endl;
    if (b % 10 >= 5)
        b += 10;
    b /= 10;

    ll v[12] = {2, 15, 33, 54, 79, 107, 138, 171, 207, 244, 284, 326};
    REP(i, 12) {
        if (b <= v[i])
            return i;
    }
    return 12;
}

string calcA(ll a) {
    ll s = 1125;
    ll d = 2250;
    string v[15] = {"NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
    REP(i, 15) {
        if (s <= a * 10 && a * 10 < s + d) {
            return v[i];
        }
        s += d;
    }
    return "N";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B;
    cin >> A >> B;

    ll b = calcB(B);
    string a = b == 0 ? "C" : calcA(A);
    cout << a << " " << b << endl;
    return 0;
}