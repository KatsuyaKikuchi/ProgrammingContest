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
    vector<ll> v;
    ll n = 1;
    while (n * n <= N) {
        if (N % n == 0) {
            ll s = N / n;
            v.push_back(s);
            if (s != n)
                v.push_back(n);
        }
        n++;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    REP(i, v.size()) {
        ll m = N / v[i] - 1;
        if (m >= 1) {
            ll x = N / m, y = N % m;
            if (x == y)
                ans += m;
        }
    }
    cout << ans << endl;
    return 0;
}