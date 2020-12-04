#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N;
    cin >> N;
    ll t = N;
    vector<pll> p;
    for (ll i = N - 1; i >= 1; --i) {
        p.push_back(pll(t, i));
        t = (t + i + 1) / 2;
    }
    cout << t << endl;
    REP(i, p.size()) {
        cout << p[i].first << " " << p[i].second << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}