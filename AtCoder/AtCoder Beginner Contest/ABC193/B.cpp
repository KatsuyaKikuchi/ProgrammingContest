#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll A, P, X;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Data> D(N);
    REP(i, N) {
        cin >> D[i].A >> D[i].P >> D[i].X;
    }
    ll ans = INF;
    REP(i, N) {
        if (D[i].A >= D[i].X)
            continue;
        ans = std::min(ans, D[i].P);
    }
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}