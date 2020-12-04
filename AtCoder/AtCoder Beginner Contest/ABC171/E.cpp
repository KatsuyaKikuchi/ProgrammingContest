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

ll L[200005];
ll R[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    memset(R, 0, sizeof(R));
    memset(L, 0, sizeof(L));
    REP(i, N) {
        L[i + 1] = L[i] ^ A[i];
    }
    for (int i = N - 1; i >= 0; --i) {
        R[i] = R[i + 1] ^ A[i];
    }

    REP(i, N) {
        B[i] = L[i] ^ R[i + 1];
    }

    REP(i, N) {
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}