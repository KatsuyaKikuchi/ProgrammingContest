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
    ll S;
    ll F;
};

Data D[505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N - 1) {
        cin >> D[i].C >> D[i].S >> D[i].F;
    }

    REP(i, N) {
        ll t = 0;
        FOR(j, N - 1, i) {
            t += ()
        }
        cout << t << endl;
    }
    return 0;
}