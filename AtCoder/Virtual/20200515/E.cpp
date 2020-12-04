#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[305 * 305];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, D;
    cin >> H >> W >> D;
    REP(i, H) {
        REP(j, W) {
            ll a;
            cin >> a;
            A[a - 1] = pll(i, j);
        }
    }
    vector<vector<ll>> S(D);
    REP(i, D) {
        S[i].push_back(0);
        for (ll j = 1; i + D * j < H * W; ++j) {
            ll x = i + D * j, y = i + D * (j - 1);
            S[i].push_back(S[i][j - 1] + abs(A[x].first - A[y].first) + abs(A[x].second - A[y].second));
        }
    }

    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        ll index = l % D;
        ll x = l / D;
        ll y = r / D;
        cout << S[index][y] - S[index][x] << endl;
    }
    return 0;
}