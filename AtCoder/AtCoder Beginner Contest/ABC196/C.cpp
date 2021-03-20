#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll get(ll x) {
    vector<ll> v;
    ll ret = x;
    while (x > 0) {
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    REP(i, v.size()) {
        ret = ret * 10LL + v[i];
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = 0;
    REP(i, S.length()) {
        N = N * 10LL + S[i] - '0';
    }
    ll len = S.length() / 2;
    ll mx = pow(10LL, len);
    ll ans = 0;
    FOR(x, mx, 1) {
        ll n = get(x);
        if (n <= N) {
            ans++;
            //cout << n << endl;
        }
    }
    cout << ans << endl;
    return 0;
}