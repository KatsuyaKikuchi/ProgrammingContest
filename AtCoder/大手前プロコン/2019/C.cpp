#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005], B[100005];
ll C[100005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    memset(B, 0, sizeof(B));
    REP(i, N) {
        ll b;
        cin >> b;
        B[b]++;
    }

    memset(C, 0, sizeof(C));

    ll ans = N;
    REP(i, N) {
        C[A[i]]++;
        ans = std::min(ans, B[A[i]] / C[A[i]]);
        cout << ans << endl;
    }
    return 0;
}