#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll g0(ll n) {
    vector<ll> v;
    ll x = n;
    while (x > 0) {
        v.push_back(x % 10);
        x /= 10;
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll ret = 0;
    REP(i, v.size()) {
        ret = ret * 10LL + v[i];
    }
    return ret;
}

ll g1(ll n) {
    vector<ll> v;
    ll x = n;
    while (x > 0) {
        v.push_back(x % 10);
        x /= 10;
    }
    sort(v.begin(), v.end());
    ll ret = 0;
    REP(i, v.size()) {
        ret = ret * 10LL + v[i];
    }
    return ret;
}

ll f(ll n) {
    return g0(n) - g1(n);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    ll ans = N;
    REP(i, K) {
        ans = f(ans);
    }
    cout << ans << endl;
    return 0;
}