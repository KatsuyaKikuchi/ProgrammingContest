#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[200005];

int main() {
    ll N;
    cin >> N;
    ll min = INF;
    ll ans = 0;
    REP(i, N) {
        cin >> P[i];
        min = std::min(min, P[i]);
        if (P[i] <= min)
            ans++;
    }
    cout << ans << endl;
    return 0;
}