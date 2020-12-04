#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) (1e9) * 2LL;

ll calc(ll X, ll s) {
    ll ret = 0, ng = INF;
    while (abs(ret - ng) > 1) {
        ll mid = (ret + ng) / 2;
        ll sum = mid * (s + mid - 1);
        if (sum > X)
            ng = mid;
        else
            ret = mid;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll X, Y;
    cin >> X >> Y;
    ll x = abs(X - Y);
    if (x <= 1)
        cout << "Brown" << endl;
    else
        cout << "Alice" << endl;
    return 0;
}