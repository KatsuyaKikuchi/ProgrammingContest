#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll N, M;
    cin >> N >> M;
    double L = 30.0 * (N % 12 + (M / 60.0));
    double S = 360.0 * M / 60.0;

    double D = abs(L-S);
    cout << OF64 << std::min(360.0 - D, D) << endl;
    return 0;
}