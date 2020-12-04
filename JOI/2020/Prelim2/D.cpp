#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll D[10][10] = {{0, 1, 2, 3, 2, 3, 4, 3, 4, 5},
                {1, 0, 1, 2, 1, 2, 3, 2, 3, 4},
                {2, 1, 0, 1, 2, 1, 2, 3, 2, 3},
                {3, 2, 1, 0, 3, 2, 1, 4, 3, 2},
                {2, 1, 2, 3, 0, 1, 2, 1, 2, 3},
                {3, 2, 1, 2, 1, 0, 1, 2, 1, 2},
                {4, 3, 2, 1, 2, 1, 0, 3, 2, 1},
                {3, 2, 3, 4, 1, 2, 3, 0, 1, 2},
                {4, 3, 2, 3, 2, 1, 2, 1, 0, 1},
                {5, 4, 3, 2, 3, 2, 1, 2, 1, 0}};

ll num(ll m) {
    ll p = 0;
    ll n = 0;
    vector<ll> v;
    while (m > 0) {
        v.push_back(m % 10);
        m /= 10;
    }

    for (int i = v.size() - 1; i >= 0; --i) {
        n += D[p][v[i]];
        n++;
        p = v[i];
    }

    return n;
}

int main() {
    ll M, R;
    cin >> M >> R;

    ll ans = INF;
    REP(i, M * 10) {
        ll m = R + i * M;
        ans = std::min(ans, num(m));
    }
    cout << ans << endl;
    return 0;
}