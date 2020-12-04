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
    ll nim = 0;
    REP(i, N) {
        ll X[3];
        cin >> X[0] >> X[1] >> X[2];
        ll M;
        cin >> M;
        pll x[3];
        REP(j, 3) {
            x[j] = pll(INF, 0);
        }
        REP(j, M) {
            REP(k, 3) {
                ll a;
                cin >> a;
                x[k].first = std::min(x[k].first, a);
                x[k].second = std::max(x[k].second, a);
            }
        }
        REP(j, 3) {
            nim ^= x[j].first;
            nim ^= X[j] - x[j].second - 1;
        }
    }
    if (nim == 0)
        cout << "LOSE" << endl;
    else
        cout << "WIN" << endl;
    return 0;
}