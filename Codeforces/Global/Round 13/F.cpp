#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll query(vector<ll> &left, vector<ll> &right) {
    cout << "? " << left.size() << " " << right.size() << endl;
    for (auto &n : left) {
        cout << n + 1 << " ";
    }
    cout << endl;
    for (auto &n : right) {
        cout << n + 1 << " ";
    }
    cout << endl;
    ll ret = 0;
    cin >> ret;
    return ret;
}

void result(vector<ll> &ans) {
    cout << "! " << ans.size();
    for (auto &n : ans) {
        cout << " " << n + 1;
    }
    cout << endl;
}

void solve() {
    ll N;
    cin >> N;

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