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
ll B[200005];
ll S[1000005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
        B[i] = A[i] + (N - i);
    }

    memset(S, 0, sizeof(S));
    REP(i, N) {
        S[B[i]] += A[i];
    }
    ll ans = 0;
    REP(i, N) {
        ans = std::max(S[B[i]], ans);
    }
    cout << ans << endl;
    return 0;
}