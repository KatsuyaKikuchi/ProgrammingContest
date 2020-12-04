#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

double P[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> P[i];
    }

    double sum = 0;
    REP(i, K) {
        sum += (P[i] * (P[i] + 1) / 2) / P[i];
    }
    double ans = sum;
    FOR(i, N, K) {
        sum += (P[i] * (P[i] + 1) / 2) / P[i];
        sum -= (P[i - K] * (P[i - K] + 1) / 2) / P[i - K];
        ans = std::max(ans, sum);
    }
    cout << OF64 << ans << endl;
    return 0;
}