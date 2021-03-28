#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[105];
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, X, Y;
    cin >> H >> W >> X >> Y;
    REP(i, H) {
        cin >> S[i];
    }
    ll ans = 1;
    X--;
    Y--;
    REP(i, 4) {
        FOR(n, 105, 1) {
            ll h = X + x[i] * n, w = Y + y[i] * n;
            if (h >= H || w >= W || h < 0 || w < 0)
                break;
            if (S[h][w] == '#')
                break;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}