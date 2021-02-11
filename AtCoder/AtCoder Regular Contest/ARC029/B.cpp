#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A, B;
long double theta;

void rot(long double &x, long double &y) {
    long double tx = x, ty = y;
    long double cs = cos(theta), sn = sin(theta);
    x = tx * cs - ty * sn;
    y = tx * sn + ty * cs;
}

bool solve() {
    ll X, Y;
    cin >> X >> Y;
    if (X > Y)
        swap(X, Y);
    if (X >= A && Y >= B)
        return true;
    long double len0 = sqrt(pow(A * 0.5, 2) + pow(B * 0.5, 2));
    long double len1 = sqrt(pow(X * 0.5, 2) + pow(Y * 0.5, 2));
    if (len0 > len1)
        return false;
    long double x = len0;
    long double y = 0;
    if (len0 > X * 0.5) {
        y = sqrt(len0 * len0 - pow(X * 0.5, 2));
        x = X * 0.5;
    }
    rot(x, y);
    return y <= (Y * 0.5) && abs(x) <= (X * 0.5);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> A >> B;
    if (A > B)
        swap(A, B);
    theta = atan((A * 0.5) / (B * 0.5)) * 2.0;
    ll N;
    cin >> N;
    REP(i, N) {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}