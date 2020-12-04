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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll f = 0, t = 0, o = 0;
    REP(i, N) {
        ll a;
        cin >> a;
        if (a % 4 == 0)
            f++;
        else if (a % 2 == 0)
            t++;
        else
            o++;
    }
    if (o == 0)
        cout << "Yes" << endl;
    else {
        o += std::min(1LL, t);
        if (f == 0 || f + 1 < o)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}