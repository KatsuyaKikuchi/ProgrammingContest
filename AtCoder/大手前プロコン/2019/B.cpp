#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[2005];

int main() {
    ll M, N, K;
    cin >> M >> N >> K;
    memset(A, 0, sizeof(A));
    REP(i, N) {
        ll a;
        cin >> a;
        A[a]++;
    }

    ll max = 0;
    FOR(i, M + 1, 1) {
        ll m = A[i];
        FOR(j, K + 1, 1) {
            if ((i - j > 0 && A[i - j] > 0) || (i + j <= M && A[i + j] > 0))
                m++;
        }
        max = std::max(m, max);
    }
    cout << max << endl;
    return 0;
}