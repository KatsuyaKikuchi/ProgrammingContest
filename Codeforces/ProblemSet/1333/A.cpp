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
    ll N, M;
    cin >> N >> M;
    vector<string> v(N);
    REP(i, N) {
        string s = "";
        REP(j, M) {
            s.push_back('B');
        }
        v[i] = s;
    }
    v[0][0] = 'W';
    REP(i, N) {
        cout << v[i] << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(i, Q) {
        solve();
    }
    return 0;
}