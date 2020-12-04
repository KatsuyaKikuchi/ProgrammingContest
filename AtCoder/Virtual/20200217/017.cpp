#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[105];
bool U[10005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    memset(U, 0, sizeof(U));
    U[0] = true;
    ll sum = 0;
    REP(i, N) {
        for (ll s = sum; s >= 0; --s) {
            if (U[s]) {
                U[s + A[i]] = true;
                sum = std::max(sum, s + A[i]);
            }
        }
    }

    ll ans = 0;
    REP(i, sum + 1) {
        if (U[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}