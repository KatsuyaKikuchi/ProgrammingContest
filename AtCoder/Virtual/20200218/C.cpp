#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e9;

struct Data {
    pll g;
    ll h;
};

Data D[105];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> D[i].g.first >> D[i].g.second >> D[i].h;
    }
    sort(D, D + N, [](Data a, Data b) { return a.h > b.h; });

    for (ll x = 0; x <= 100; ++x) {
        for (ll y = 0; y <= 100; ++y) {
            ll h = D[0].h + abs(D[0].g.first - x) + abs(D[0].g.second - y);
            if (h < 1)
                continue;
            bool exist = true;
            REP(i, N) {
                ll th = std::max(0LL, h - abs(D[i].g.first - x) - abs(D[i].g.second - y));
                if (D[i].h != th) {
                    exist = false;
                    break;
                }
            }
            if (exist) {
                cout << x << " " << y << " " << h << endl;
                return 0;
            }
        }
    }
    return 0;
}