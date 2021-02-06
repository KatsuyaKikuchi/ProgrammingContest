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
    if (N == 1) {
        cout << 2 << endl;
        return 0;
    }
    ll sum = 0;
    ll ans = 0;
    ll s = 1;
    while (true) {
        sum += s;
        if (N < sum)
            break;
        if ((N - sum) % s == 0)
            ans++;
        s++;
    }
    cout << ans * 2LL << endl;
    return 0;
}