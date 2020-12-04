#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[30];
ll B[30][30];

int main() {
    string S;
    cin >> S;
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    REP(i, S.length()) {
        ll n = S[i] - 'a';
        REP(j, 26) {
            B[j][n] += A[j];
        }
        A[n]++;
    }

    ll ans = 0;
    REP(i, 26) {
        ans = std::max(A[i], ans);
        REP(j, 26) {
            ans = std::max(ans, B[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}