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
    string S, T;
    cin >> S >> T;
    ll ans = INF;
    REP(i, S.length()) {
        ll m = 0;
        REP(j, T.length()) {
            if (j + i >= S.length()) {
                m = INF;
                break;
            }
            if (T[j] == S[i + j])
                continue;
            m++;
        }
        ans = std::min(ans, m);
    }
    cout << ans << endl;
    return 0;
}