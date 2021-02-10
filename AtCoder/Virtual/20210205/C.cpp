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
    ll ans = 0;
    ll sum = 1;
    ll len = 1;
    while (sum <= N) {
        if ((N - sum) % len == 0)
            ans++;
        len++;
        sum += len;
    }
    cout << ans * 2LL << endl;
    return 0;
}