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
    ll N, M, T;
    cin >> N >> M >> T;
    ll mx = N;
    ll p = 0;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        N -= (a - p);
        if (N <= 0) {
            cout << "No" << endl;
            return 0;
        }
        N += (b - a);
        N = std::min(N, mx);
        p = b;
    }

    N -= (T - p);
    if (N > 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}