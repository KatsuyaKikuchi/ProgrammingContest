#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[300005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, M;
    cin >> H >> W >> M;
    vector<pll> X, Y;
    REP(i, H) {
        X.push_back(pll(0, i));
    }
    REP(i, W) {
        Y.push_back(pll(0, i));
    }

    std::map<pll, ll> mp;
    REP(i, M) {
        cin >> A[i].first >> A[i].second;
        A[i].first--;
        A[i].second--;
        mp[A[i]]++;
        X[A[i].first].first++;
        Y[A[i].second].first++;
    }

    sort(X.begin(), X.end(), greater<pll>());
    sort(Y.begin(), Y.end(), greater<pll>());

    ll xm = X[0].first, ym = Y[0].first;

    ll ans = xm + ym - 1;
    vector<ll> x, y;
    REP(i, X.size()) {
        if (X[i].first < xm)
            break;
        x.push_back(X[i].second);
    }
    REP(i, Y.size()) {
        if (Y[i].first < ym)
            break;
        y.push_back(Y[i].second);
    }

    REP(i, x.size()) {
        REP(j, y.size()) {
            pll p(x[i], y[j]);

            if (mp[p] == 0) {
                cout << xm + ym << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;
    return 0;
}