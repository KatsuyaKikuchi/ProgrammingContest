#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[30];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> P[i];
    }
    ll ans = 0;
    FOR(i, N - 1, 1) {
        if (P[i - 1] < P[i] && P[i] < P[i + 1])
            ans++;
        if (P[i - 1] > P[i] && P[i] > P[i + 1])
            ans++;
    }
    cout << ans << endl;
    return 0;
}