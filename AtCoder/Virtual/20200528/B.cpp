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
    pll p(0, 0);
    ll pt = 0;
    bool e = true;
    REP(i, N) {
        pll n;
        ll t;
        cin >> t >> n.first >> n.second;

        ll d = abs(n.first - p.first) + abs(n.second - p.second);

        if ((t - pt) - d < 0 || ((t - pt) - d) % 2 == 1) {
            e = false;
        }
        pt = t;
        p = n;
    }
    if (e)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}