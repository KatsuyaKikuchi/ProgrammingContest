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
    cin >> N;
    vector<ll> M(N + 1, 1);
    ll ans = 0;
    REP(i, N) {
        ll x = i + 1;
        ans += x * M[x];
        for (ll j = x; j <= N; j += x) {
            M[j]++;
        }
    }
    cout << ans << endl;
    return 0;
}