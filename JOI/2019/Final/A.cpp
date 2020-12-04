#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[3005];
ll O[3005][3005];

int main() {
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    memset(O, 0, sizeof(O));
    REP(i, H) {
        for (ll j = W - 1; j >= 0; --j) {
            O[i][j] += O[i][j + 1];
            if (S[i][j] == 'O')
                O[i][j]++;
        }
    }

    ll ans = 0;
    REP(j, W) {
        ll s = 0;
        REP(i, H) {
            if (S[i][j] == 'J')
                s += O[i][j];
            if (S[i][j] == 'I')
                ans += s;
        }
    }
    cout << ans << endl;
    return 0;
}