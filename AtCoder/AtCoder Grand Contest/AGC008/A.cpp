#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll X, Y;
    cin >> X >> Y;
    ll ans = INF;
    if (Y >= X) {
        if (X < 0)
            ans = std::min(abs(Y - X), abs(Y + X) + 1);
        else
            ans = Y - X;
    }
    else if (abs(Y) >= X) {
        if (X < 0)
            ans = std::min(abs(Y) - X + 1, abs(Y) + X + 2);
        else
            ans = abs(Y) - X + 1;
    }
    else {
        if (Y >= 0)
            ans = std::min(X - Y + 2, 1 + Y + X);
        else
            ans = X - abs(Y) + 1;
    }
    cout << ans << endl;
    return 0;
}