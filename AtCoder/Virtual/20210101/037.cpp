#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll func(ll n) {
    ll ret = 0;
    while (n > 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> ans;
    REP(t, 1000) {
        ll x = N - t;
        if (x <= 0)
            break;
        ll s = x + func(x);
        if (s == N)
            ans.push_back(x);
    }


    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}