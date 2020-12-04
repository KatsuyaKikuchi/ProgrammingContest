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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll max = 0;
    ll m = 0;
    REP(i, 2 * N) {
        if (A[i % N] == A[(i + 1) % N] && A[i % N] == A[(N + i - 1) % N])
            m++;
        else
            m = 0;

        max = std::max(max, m);
    }

    if (max >= N)
        cout << -1 << endl;
    else
        cout << (max + 1) / 2 + 1 << endl;
    return 0;
}