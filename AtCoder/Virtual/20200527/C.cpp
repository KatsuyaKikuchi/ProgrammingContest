#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> H[i];
    }
    ll ans = 0;
    while (true) {
        bool update = false;
        ll last = -1;
        REP(i, N) {
            if (H[i] > 0) {
                H[i]--;
                update = true;
                continue;
            }
            if (last != i - 1)
                ans++;
            last = i;
        }
        if (last != N - 1)
            ans++;
        if (!update)
            break;
    }
    cout << ans << endl;
    return 0;
}