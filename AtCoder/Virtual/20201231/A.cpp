#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, K;
    cin >> H >> W >> K;
    REP(i, H) {
        cin >> S[i];
    }

    ll ans = 0;
    REP(hb, pow(2, H)) {
        REP(wb, pow(2, W)) {
            ll num = 0;
            REP(i, H) {
                if ((hb >> i) & 1)
                    continue;
                REP(j, W) {
                    if ((wb >> j) & 1)
                        continue;
                    if (S[i][j] == '#')
                        num++;
                }
            }
            if (num == K)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}