#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll W, H;
    cin >> W >> H;
    vector<ll> X(W), Y(H);
    ll ans = 0;
    REP(i, W) {
        cin >> X[i];
        ans += X[i];
    }
    REP(i, H) {
        cin >> Y[i];
        ans += Y[i];
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.push_back(INF);
    Y.push_back(INF);
    REP(i, W) {
        ll idx = lower_bound(Y.begin(), Y.end(), X[i] + 1) - Y.begin();
        ans += (H - idx) * X[i];
    }
    REP(i, H) {
        ll idx = lower_bound(X.begin(), X.end(), Y[i]) - X.begin();
        ans += (W - idx) * Y[i];
    }
    cout << ans << endl;
    return 0;
}