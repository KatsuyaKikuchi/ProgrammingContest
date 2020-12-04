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
    vector<vector<pll>> A(N);
    REP(i, N) {
        ll a;
        cin >> a;
        REP(j, a) {
            ll x, y;
            cin >> x >> y;
            x--;
            A[i].push_back(pll(x, y));
        }
    }

    ll ans = 0;
    REP(i, pow(2LL, N)) {
        bool f = true;
        REP(j, N) {
            if ((i >> j) & 1) {
                REP(k, A[j].size()) {
                    if (((i >> A[j][k].first) & 1) != A[j][k].second)
                        f = false;
                }
            }
        }

        if (f) {
            ll s = 0;
            REP(j, N) {
                if ((i >> j) & 1)
                    s++;
            }
            ans = std::max(s, ans);
        }
    }
    cout << ans << endl;
    return 0;
}