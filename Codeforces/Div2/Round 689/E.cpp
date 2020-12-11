#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve(ll K, ll L, ll R, ll T, ll X, ll Y) {
    R -= L;
    K -= L;
    if (K + Y <= R) {
        if (K + Y - X < 0)
            return false;
    }
    else {
        if (K - X < 0)
            return false;
    }
    if (X == Y) {
        return true;
    }
    if (K + Y <= R)
        K += Y;
    if (Y < X) {
        return (K - X) / (X - Y) >= T - 1;
    }
    if (R - Y >= X - 1)
        return true;
    if (R - Y < 0) {
        ll d = K / X;
        if (T <= d)
            return true;
        return false;
    }

    //! 残りの水が R-Y+1<=x<=L+X-1になったらオワオワリ
    {
        ll y = (R - Y) % X;
        ll d = K % X;
        //! mod Xが0,1,...,yならばok , それ以上はng
        ll day = K / X;
        vector<bool> seen(X, false);
        while (d <= y) {
            if (seen[d])
                return true;
            seen[d] = true;
            d = d + Y;
            day += d / X;
            d %= X;
        }
        return day >= T;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K, L, R, T, X, Y;
    cin >> K >> L >> R >> T >> X >> Y;
    if (solve(K, L, R, T, X, Y))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}