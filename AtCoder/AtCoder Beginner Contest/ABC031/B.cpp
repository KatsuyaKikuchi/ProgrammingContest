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
    ll L, H, N;
    cin >> L >> H >> N;
    REP(i, N) {
        ll a;
        cin >> a;
        ll d = a - L;
        if (d < 0)
            cout << abs(d) << endl;
        else if (a > H)
            cout << -1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}