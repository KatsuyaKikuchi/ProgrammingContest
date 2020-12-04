#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<pll> C[50005];
bool U[100005];

int main() {
    ll N, M, T;
    cin >> N >> M >> T;
    REP(i, M) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        C[x].push_back(pll(y, i));
        C[y].push_back(pll(x, i));
    }
    return 0;
}