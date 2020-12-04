#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> H[i];
    }

    ll ans = 0;
    REP(_, 101) {
        ll n = 0;
        REP(i, N + 1) {
            if (H[i] == 0) {
                if (n > 0)
                    ans++;
                n = 0;
                continue;
            }
            H[i]--;
            n++;
        }
    }
    cout << ans << endl;
    return 0;
}