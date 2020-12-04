#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll T0, T1;
    cin >> T0 >> T1;
    pll A, B;
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;

    ll fa = A.first * T0, fb = B.first * T0;
    ll sa = fa + A.second * T1, sb = fb + B.second * T1;

    if (sa == sb) {
        cout << "infinity" << endl;
        return 0;
    }

    if ((fa < fb && sa < sb) || (fa > fb && sa > sb)) {
        cout << 0 << endl;
        return 0;
    }

    ll d = abs(sa - sb);
    ll ans = (abs(fa - fb) / d) * 2LL;
    if (abs(fa - fb) % d > 0)
        ans++;
    cout << ans << endl;
    return 0;
}