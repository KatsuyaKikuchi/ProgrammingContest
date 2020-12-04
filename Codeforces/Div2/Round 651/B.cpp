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
    vector<pll> od, ev;
    REP(i, 2 * N) {
        ll a;
        cin >> a;
        if (a % 2 == 0)
            ev.push_back(pll(a, i));
        else
            od.push_back(pll(a, i));
    }
    vector<pll> v;
    {
        ll index = 0;
        while (index + 1 < od.size() && v.size() < N - 1) {
            v.push_back(pll(od[index].second, od[index + 1].second));
            index += 2;
        }
    }
    {
        ll index = 0;
        while (v.size() < N - 1) {
            v.push_back(pll(ev[index].second, ev[index + 1].second));
            index += 2;
        }
    }

    REP(i, v.size()) {
        cout << v[i].first + 1 << " " << v[i].second + 1 << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        solve();
    }
    return 0;
}