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
    ll n = N + 1;
    ll ok = 0, ng = 1500000000;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        ll s = mid * (mid + 1) / 2;
        if (s <= n)
            ok = mid;
        else
            ng = mid;
    }
    // cout << ok << endl;
    cout << 1 + (N - ok) << endl;
    return 0;
}