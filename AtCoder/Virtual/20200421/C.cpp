#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[100005];
ll U[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        S[i] = 1;
        U[i] = false;
    }
    U[0] = true;
    REP(i, M) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        S[x]--;
        S[y]++;
        if (U[x])
            U[y] = true;
        if (S[x] == 0)
            U[x] = false;
    }

    ll ans = 0;
    REP(i, N) {
        if (U[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}