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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll n = 1;
    ll ans = N - 1;
    while (n * n <= N) {
        if (N % n == 0) {
            ans = std::min(ans, n - 1 + N / n - 1);
        }
        n++;
    }
    cout << ans << endl;
    return 0;
}