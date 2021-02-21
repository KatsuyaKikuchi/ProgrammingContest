#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll mod_pow(ll n, ll r, ll m) {
    ll ret = 1;
    ll p = n % m;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % m;
        r /= 2;
        p = p * p % m;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, C;
    cin >> A >> B >> C;
    A %= 10;
    if (A == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (A == 1) {
        cout << 1 << endl;
        return 0;
    }

    ll cnt = 1;
    ll a = A;
    while (true) {
        a = a * A % 10;
        if (a == A)
            break;
        cnt++;
    }
    //cout << cnt << endl;
    ll p = mod_pow(B, C, cnt);
    p = (p - 1 + cnt) % cnt;
    ll ans = A % 10;
    REP(_, p) {
        ans = ans * A % 10;
    }
    cout << ans << endl;
    return 0;
}