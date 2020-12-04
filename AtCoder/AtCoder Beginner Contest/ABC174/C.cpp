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
    ll K;
    cin >> K;

    if (K % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    ll t = 7;
    REP(i, K + 10) {
        t = t % K;

        if (t == 0) {
            cout << i + 1 << endl;
            return 0;
        }
        //cout << t << endl;

        t = t * 10LL + 7;
    }

    cout << -1 << endl;
    return 0;
}