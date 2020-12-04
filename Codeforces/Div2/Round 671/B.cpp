#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll X;
    cin >> X;
    ll sum = 1;
    ll ret = 1;
    ll num = 1;
    ll p = 1;
    while (true) {
        p *= 2LL;
        num = num * 2LL + p * p;
        if (sum > X - num) {
            break;
        }
        sum += num;
        ret++;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}