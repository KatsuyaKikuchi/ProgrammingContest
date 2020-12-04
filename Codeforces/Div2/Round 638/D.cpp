#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N;
    cin >> N;
    ll d = 0;
    ll p = 2;
    while (N > p - 1) {
        p *= 2;
        d++;
    }
    cout << d << endl;
    ll n = 1;
    ll s = 1;
    REP(i, d) {
        ll r = (d - i);

        ll ok = 0, ng = n + 1;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if ((n + mid) * r + s <= N)
                ok = mid;
            else
                ng = mid;
        }
        cout << ok << " ";
        n += ok;
        s += n;
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}