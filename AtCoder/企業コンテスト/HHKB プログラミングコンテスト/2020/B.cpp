#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            if (i + 1 < H) {
                if (S[i][j] == '.' && S[i + 1][j] == '.')
                    ans++;
            }
            if (j + 1 < W) {
                if (S[i][j] == '.' && S[i][j + 1] == '.')
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}