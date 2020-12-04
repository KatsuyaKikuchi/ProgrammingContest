#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 61;

ll A[200005];
ll B[200005][MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
        A[i]--;
        B[i][0] = A[i];
    }
    FOR(i, MAX, 1) {
        REP(j, N) {
            B[j][i] = B[B[j][i - 1]][i - 1];
        }
    }

    ll ans = 0;
    REP(i, MAX) {
        if (((K >> i) & 1) == 0)
            continue;
        ans = B[ans][i];
    }
    cout << ans + 1 << endl;
    return 0;
}