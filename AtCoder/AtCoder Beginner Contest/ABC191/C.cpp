#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[15];
ll x[4] = {0, 0, 1, 1};
ll y[4] = {0, 1, 0, 1};

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
            ll n = 0;
            REP(k, 4) {
                ll h = i + x[k], w = j + y[k];
                if (h >= H || w >= W)
                    continue;
                if (S[h][w] == '#')
                    n++;
            }
            if (n % 2 == 1)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}