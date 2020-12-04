#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll D[55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    memset(D, 0, sizeof(D));
    REP(i, N) {
        cin >> D[i];
    }
    sort(D, D + N);
    vector<ll> v;
    v.push_back(0);
    REP(i, N) {
        if (i % 2 == 0)
            v.push_back(D[i]);
        else
            v.push_back(24 - D[i]);
    }

    ll ans = INF;
    REP(i, v.size()) {
        FOR(j, v.size(), i + 1) {
            ll a = v[i];
            ll b = v[j];
            ll d = std::min(abs(a - b), 24 - abs(a - b));
            ans = std::min(ans, d);
        }
    }
    cout << ans << endl;
    return 0;
}