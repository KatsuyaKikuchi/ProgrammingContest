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
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll n = (C + D - 1) / D;
    {
        //! -1 check
        ll p = C % D;
        ll heal = (n - 1) * B * D;
        if (p == 0)
            heal += B * D;
        else
            heal += B * p;
        if (heal < A)
            return -1;
    }
    ll ok = 0, ng = n;
    while (abs(ng - ok) > 1) {
        ll mid = (ok + ng) / 2;
        ll heal = mid * B * D;
        if (heal >= A)
            ng = mid;
        else
            ok = mid;
    }
    ll a = B * D;
    ll d = B * D;

    return A + ok * A - ok * (2 * a + (ok - 1) * d) / 2;
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