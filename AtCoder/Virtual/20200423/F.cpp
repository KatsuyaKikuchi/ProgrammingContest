#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e16;

ll calc(ll A, vector<ll> v) {
    ll m = 0;
    ll a = 0;
    while (a > 0) {
        a /= 10;
        m++;
    }
}

ll dfs(ll A, ll K, vector<ll> v, ll s = -1) {
    if (v.size() == K) {
        return calc(A, v);
    }

    if (9 - s + v.size() < K) {
        return INF;
    }
    ll ret = INF;
    for (ll i = s + 1; i < 10; ++i) {
        v.push_back(i);
        ret = std::min(ret, dfs(A, K, v, i));
        v.pop_back();
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, K;
    cin >> A >> K;
    vector<ll> v;
    cout << dfs(A, K, v) << endl;
    return 0;
}