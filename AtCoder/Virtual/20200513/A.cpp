#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[15];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N = 12;
    REP(i, N) {
        cin >> S[i];
    }

    ll ans = 0;
    REP(i, N) {
        REP(j, S[i].length()) {
            if (S[i][j] == 'r') {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}