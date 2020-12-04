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
    ll X[3];
    REP(i, 3) {
        cin >> X[i];
    }
    ll Y[3];
    REP(i, 3) {
        cin >> Y[i];
    }

    ll ans = 0;
    vector<ll> v{0, 1, 2};
    do {
        vector<ll> t{0, 1, 2};
        do {
            ll n = 1;
            REP(i, 3) {
                n *= X[v[i]] / Y[t[i]];
            }
            ans = std::max(ans, n);
        } while (next_permutation(t.begin(), t.end()));
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
    return 0;
}