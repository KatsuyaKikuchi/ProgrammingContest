#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> C[i];
    }

    ll len = 0;
    ll l = 0;
    REP(i, 2 * N) {
        if (C[i % N] != C[(i + 1) % N])
            l = 0;
        len = std::max(len, ++l);
    }

    if (len >= N)
        cout << -1 << endl;
    else
        cout << (len + 1) / 2 << endl;
    return 0;
}