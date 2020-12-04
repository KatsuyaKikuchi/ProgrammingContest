#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[25];
ll B[25];
ll C[25];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll ans = 0;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
        ans += B[i];
    }
    REP(i, N - 1) {
        cin >> C[i];
    }
    REP(i, N - 1) {
        if (A[i + 1] == A[i] + 1)
            ans += C[A[i] - 1];
    }
    cout << ans << endl;
    return 0;
}