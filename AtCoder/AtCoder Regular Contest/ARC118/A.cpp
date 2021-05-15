#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e16;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T, N;
    cin >> T >> N;

    ll count = 0;
    ll prev = 0;
    REP(i, 100) {
        ll n = i + 1;
        ll p = T * n / 100;
        if (p != prev)
            count++;
        prev = p;
    }
    //1->100までの間にcount個ある
    //    cout << count << endl;

    ll ok = 0, ng = INF;
    while (abs(ng - ok) > 1) {
        ll mid = (ok + ng) / 2;
        if (mid * count >= N)
            ng = mid;
        else
            ok = mid;
    }
    ll x = ok * 100LL + 1;
    ll nn = N - (ok * count);
    prev = T * x / 100;

    while (nn > 0) {
        ll p = T * x / 100;
        if (p != prev)
            nn--;
        if (nn == 0)
            break;
        prev = p;
        x++;
    }
    cout << x + N - 1 << endl;
    return 0;
}