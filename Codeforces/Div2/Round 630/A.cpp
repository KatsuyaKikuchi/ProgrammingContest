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
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        pll s;
        cin >> s.first >> s.second;
        pll l, r;
        cin >> l.first >> l.second >> r.first >> r.second;

        bool ans = true;
        ll x = s.first - a + b;
        ll y = s.second - c + d;
        if (l.first <= x && r.first >= x && l.second <= y && r.second >= y)
            ans = true;
        else
            ans = false;

        if (l.first == r.first && (a > 0 || b > 0))
            ans = false;
        if (l.second == r.second && (c > 0 || d > 0))
            ans = false;

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}