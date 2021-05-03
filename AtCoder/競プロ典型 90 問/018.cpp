#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

double T, L, X, Y;

double solve(double t) {
    double theta = 2.0 * M_PI * (t / T);
    double y = -L * 0.5 * sin(theta);
    double z = L * 0.5 * (1 - cos(theta));
    double len = sqrt(X * X + (Y - y) * (Y - y));
    return atan2(z, len) / M_PI * 180;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T >> L >> X >> Y;
    ll Q;
    cin >> Q;
    REP(_, Q) {
        double E;
        cin >> E;
        cout << OF64 << solve(E) << endl;
    }
    return 0;
}