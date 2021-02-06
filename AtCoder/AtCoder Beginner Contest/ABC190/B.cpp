#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, S, D;
    cin >> N >> S >> D;
    bool e = false;
    REP(i, N) {
        ll x, y;
        cin >> x >> y;
        if (x < S && y > D)
            e = true;
    }
    if (e)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}