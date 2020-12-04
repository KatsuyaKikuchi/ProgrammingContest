#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[5];

ll query(ll x) {
    cout << x << endl;
    ll ret;
    cin >> ret;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 3) {
        cin >> A[i];
    }
    cout << "First" << endl;
    {
        ll mx = A[0], mn = A[0];
        REP(i, 3) {
            mx = std::max(A[i], mx);
            mn = std::min(A[i], mn);
        }
        ll x = mx - mn + 1;
        ll ret = query(x);
        if (ret == 0) {
            return 0;
        }
        A[ret - 1] += x;
    }
    while (true) {
        vector<ll> v;
        REP(i, 3) {
            v.push_back(A[i]);
        }
        sort(v.begin(), v.end());
        ll x = v[2] - v[0];
        ll y = v[2] - v[1];

        ll q = 0;
        if (2 * y == x)
            q = y;
        else
            q = x + y;

        ll ret = query(q);
        if (ret == 0)
            break;
        A[ret - 1] += q;
    }
    return 0;
}