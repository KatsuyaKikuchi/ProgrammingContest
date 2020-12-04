#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[10];

void solve() {
    REP(i, 3) {
        REP(j, 3) {
            ll h = 3 * i + j;
            ll w = 3 * j + i;
            ll c = S[h][w] - '1';
            S[h][w] = (char)((c + 1) % 9 + '1');
        }
    }

    REP(i, 9) {
        cout << S[i] << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        REP(i, 9) {
            cin >> S[i];
        }
        solve();
    }
    return 0;
}