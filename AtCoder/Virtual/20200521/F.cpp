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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll L = 0;
    ll ans = 1;
    REP(i, 2 * N) {
        if (S[i] == 'W') {
            if (L % 2 == 0) {
                ans = (ans * L) % MOD;
                L--;
            }
            else
                L++;
        }
        else {
            if (L % 2 == 0)
                L++;
            else {
                ans = (ans * L) % MOD;
                L--;
            }
        }
    }
    if (L != 0)
        ans = 0;

    REP(i, N) {
        ans = (ans * (i + 1)) % MOD;
    }
    cout << ans << endl;
    return 0;
}