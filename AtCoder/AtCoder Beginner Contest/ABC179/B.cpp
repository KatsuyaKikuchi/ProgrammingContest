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
    ll m = 0;
    ll p = 0;
    REP(i, N) {
        ll a, b;
        cin >> a >> b;
        if (a == b) {
            p++;
        }
        else
            p = 0;
        m = std::max(p, m);
    }

    if (m >= 3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}