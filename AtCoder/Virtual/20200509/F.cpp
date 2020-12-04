#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    if (N % 2 == 1) {
        REP(i, M) {
            cout << i + 1 << " " << N - 1 - i << endl;
        }
        return 0;
    }

    vector<pll> v;
    ll ev = (M / 2) * 2;
    ll od = ((M - 1) / 2) * 2 + 1;
    REP(i, N) {
        if (od <= 0)
            break;
        v.push_back(pll(i + 1, i + 1 + od));
        od -= 2;
    }
    for (ll i = N; i >= 0; --i) {
        if (ev <= 0)
            break;
        v.push_back(pll(i, i - ev));
        ev -= 2;
    }

    REP(i, v.size()) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}