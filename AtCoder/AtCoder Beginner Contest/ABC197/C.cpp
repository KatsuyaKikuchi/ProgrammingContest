#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[25];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = INF;
    REP(bit, pow(2LL, N)) {
        ll x = 0;
        ll p = 0;
        REP(i, N) {
            if (((bit >> i) & 1) == 1) {
                x ^= p;
                p = 0;
            }
            p |= A[i];
        }
        x ^= p;
        ans = std::min(x, ans);
    }
    cout << ans << endl;
    return 0;
}