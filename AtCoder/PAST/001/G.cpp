#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[15][15];

ll calc(ll n) {
    vector<ll> v;
    REP(i, 13) {
        if (((n >> i) & 1) == 1)
            v.push_back(i);
    }

    ll m = 0;
    REP(i, v.size()) {
        FOR(j, v.size(), i + 1) {
            m += A[v[i]][v[j]];
        }
    }
    return m;
}

int main() {
    ll N;
    cin >> N;
    REP(i, N - 1) {
        FOR(j, N, i + 1) {
            cin >> A[i][j];
        }
    }

    ll ans = -INF;
    ll p = pow(2, N);
    REP(i, p) {
        REP(j, p) {
            if ((i & j) > 0)
                continue;
            ll k = ((p - 1) & (~(i | j)));

            ans = std::max(ans, calc(i) + calc(j) + calc(k));
        }
    }
    cout << ans << endl;
    return 0;
}