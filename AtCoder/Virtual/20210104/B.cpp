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
    if (N % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll p = 0;
    ll x = 10;
    while (x <= N) {
        p += N / x;
        x *= 5LL;
    }
    cout << p << endl;
    return 0;
}