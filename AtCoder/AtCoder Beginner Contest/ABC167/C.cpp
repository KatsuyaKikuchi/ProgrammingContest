#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll C;
    vector<ll> v;
};

Data D[15];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, X;
    cin >> N >> M >> X;
    REP(i, N) {
        cin >> D[i].C;
        REP(j, M) {
            ll a;
            cin >> a;
            D[i].v.push_back(a);
        }
    }

    ll ans = INF;
    REP(b, pow(2, N)) {
        vector<ll> v(M, 0);
        ll cost = 0;
        REP(j, N) {
            if (((b >> j) & 1) == 0)
                continue;
            cost += D[j].C;
            REP(i, M) {
                v[i] += D[j].v[i];
            }
        }

        bool e = true;
        REP(j, M) {
            if (v[j] < X)
                e = false;
        }
        if (e)
            ans = std::min(ans, cost);
    }

    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}