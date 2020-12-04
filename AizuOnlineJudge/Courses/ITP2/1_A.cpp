#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    ll index = 0;
    REP(_, Q) {
        ll q;
        cin >> q;
        if (q == 0) {
            ll x;
            cin >> x;
            A[index++] = x;
        }
        else if (q == 1) {
            ll x;
            cin >> x;
            cout << A[x] << endl;

        }
        else {
            index--;
        }
    }
    return 0;
}