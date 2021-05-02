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
    ll N;
    double D, H;
    cin >> N >> D >> H;
    double ans = 0.0;
    REP(i, N) {
        double d, h;
        cin >> d >> h;
        double height = 0.0;
        double a = (H - h) / (D - d);
        height = max(0.0, -a * d + h);
        ans = std::max(ans, height);
    }
    cout << OF64 << ans << endl;
    return 0;
}