#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, D;
    cin >> H >> W >> D;
    REP(i, H) {
        REP(j, W) {
            ll a;
            cin >> a;
            a--;
            A[a] = pll(i, j);
        }
    }
    vector<vector<ll>> v(D);
    REP(i, D) {
        v[i].push_back(0);
        ll n = i;
        while (n + D < H * W) {
            ll c = abs(A[n].first - A[n + D].first) + abs(A[n].second - A[n + D].second) + v[i].back();
            v[i].push_back(c);
            n += D;
        }
    }

    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll l, r;
        cin >> l >> r;
        ll a = (l - 1) / D;
        ll b = (r - 1) / D;
        ll n = (l - 1) % D;
        ll ret = v[n][b] - v[n][a];
        cout << ret << endl;
    }
    return 0;
}