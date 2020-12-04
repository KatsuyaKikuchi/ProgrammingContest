#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll R[200005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> R[i];
    }

    ll max = -INF;
    ll min = R[0];
    FOR(i, N, 1) {
        max = std::max(max, R[i] - min);
        min = std::min(R[i], min);
    }
    cout << max << endl;
    return 0;
}