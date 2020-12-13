#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll cmb(ll L) {
    ll p = L;
    ll n = 11;
    ll ret = 1;
    REP(_, 11) {
        ret *= p;
        p--;
        while (n > 0 && ret % n == 0) {
            ret /= n;
            n--;
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll L;
    cin >> L;
    ll ans = 1;

    cout << cmb(L - 1) << endl;

    return 0;
}