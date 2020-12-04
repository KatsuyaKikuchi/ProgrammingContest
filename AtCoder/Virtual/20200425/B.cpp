#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
ll B[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll max = 0;
    REP(i, N) {
        cin >> A[i];
        max = std::max(max, A[i]);
    }
    memset(B, 0, sizeof(B));
    REP(i, N) {
        B[A[i]]++;
    }

    ll ans = 0;
    REP(i, max + 1) {
        ll m = B[i] + B[i + 1];
        if (i > 0)
            m += B[i - 1];
        ans = std::max(ans, m);
    }
    cout << ans << endl;
    return 0;
}