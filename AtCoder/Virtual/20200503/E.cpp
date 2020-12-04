#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = 0;
    ll s = 0;
    ll si = 0;
    REP(i, N) {
        while ((s & A[i]) != 0) {
            s -= A[si++];
        }
        ans += i - si + 1;
        s += A[i];
        continue;
    }
    cout << ans << endl;
    return 0;
}