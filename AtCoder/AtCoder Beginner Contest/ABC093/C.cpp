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
    vector<ll> v(3);
    REP(i, 3) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    ans += v[2] - v[1];
    v[0] += ans;
    v[1] += ans;
    ll d = (v[2] - v[0]);
    if (d % 2 == 0)
        ans += d / 2;
    else
        ans += (d + 1) / 2 + 1;
    cout << ans << endl;
    return 0;
}