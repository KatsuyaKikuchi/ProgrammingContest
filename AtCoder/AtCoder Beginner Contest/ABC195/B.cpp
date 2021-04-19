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
    ll A, B, W;
    cin >> A >> B >> W;
    W *= 1000;

    ll m0 = INF, m1 = 0;
    REP(i, W) {
        ll n = i + 1;
        ll w = n * A;
        ll d = B - A;
        if (w > W)
            continue;
        ll dw = W - w;
        if (d * n >= dw) {
            m0 = std::min(m0, i + 1);
            m1 = std::max(m1, i + 1);
        }
    }
    if (m0 == INF || m1 == 0) {
        cout << "UNSATISFIABLE" << endl;
    }
    else {
        cout << m0 << " " << m1 << endl;
    }
    return 0;
}