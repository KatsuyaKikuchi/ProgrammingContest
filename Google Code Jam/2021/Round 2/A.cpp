#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll MAX = (ll) 1e8;

ll query(ll a, ll b) {
    if (a > b)
        swap(a, b);
    cout << "M " << a + 1 << " " << b + 1 << endl;
    ll ret;
    cin >> ret;
    return ret - 1;
}

ll swap_query(ll a, ll b) {
    if (a > b)
        swap(a, b);
    cout << "S " << a + 1 << " " << b + 1 << endl;
    ll ret;
    cin >> ret;
    return ret;
}

ll result() {
    cout << "D" << endl;
    ll ret;
    cin >> ret;
    return ret;
}

ll cost(ll a, ll b) {
    if (a > b)
        swap(a, b);
    ll div = (b - a + 1);
    return (MAX + div - 1) / div;
}

void solve(ll N) {
    ll coin = 6LL * MAX;
    REP(i, N - 1) {

        ll cst = cost(i, N - 1);
        //ll idx = i + 1;
        coin -= cst;
        if (coin < 0)
            break;
        ll idx = query(i, N - 1);
        if (idx == i)
            continue;
        swap_query(i, idx);
    }
   // cout << coin << endl;
    result();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T, N;
    cin >> T >> N;
    REP(_, T) {
        solve(N);
    }
    return 0;
}