#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll div(ll &n) {
    ll ret = abs(n) % 2;
    if (n < 0) {
        n = (abs(n) + ret) / 2LL;
    }
    else {
        n = -(n - ret) / 2LL;
    }
    return ret;
}

string solve(ll n) {
    string ret = "";
    while (n != 0) {
        ret.push_back(div(n) + '0');
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    if (N == 0)
        cout << 0 << endl;
    else
        cout << solve(N) << endl;

    return 0;
}