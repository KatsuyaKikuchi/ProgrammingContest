#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const double PI = acos(-1);

double solve() {
    ll N;
    cin >> N;
    double len = 0;
    double theta = 180.0 * (2 * N - 2) / (2.0 * N);
    double x = 180.0 - theta;
    REP(i, N / 2) {
        len += cos(x / 180.0 * PI);
        x = 180.0 - theta + x;
    }

    return 1.0 + len * 2.0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        cout << OF64 << solve() << endl;
    }
    return 0;
}