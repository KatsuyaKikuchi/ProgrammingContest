#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> T(N);
    REP(i, N) {
        cin >> T[i];
    }

    ll ans = INF;
    REP(bit, pow(2LL, N)) {
        ll a = 0, b = 0;
        REP(i, N) {
            if ((bit >> i) & 1)
                a += T[i];
            else
                b += T[i];
        }
        ans = std::min(ans, max(a, b));
    }
    cout << ans << endl;
    return 0;
}