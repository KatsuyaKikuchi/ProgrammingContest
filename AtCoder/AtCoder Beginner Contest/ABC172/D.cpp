#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[10000005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    memset(P, 0, sizeof(P));
    REP(i, N) {
        ll n = i + 1;
        for (ll j = n; j <= N; j += n) {
            P[j]++;
        }
    }

    ll ans = 0;
    REP(i, N) {
        ans += (i + 1) * P[i + 1];
    }
    cout << ans << endl;

    return 0;
}