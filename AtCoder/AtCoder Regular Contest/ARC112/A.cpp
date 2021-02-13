#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll L, R;
    cin >> L >> R;
    ll ok = R + 1, ng = L - 1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (mid - L >= L)
            ok = mid;
        else
            ng = mid;
    }
    ll num = std::max(R - ok + 1, 0LL);
    ll ret = (num + 1) * num / 2;
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