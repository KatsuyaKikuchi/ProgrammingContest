#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[1000005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        ll a, b;
        cin >> a >> b;
        A[a]++;
        A[b + 1]--;
    }

    ll max = A[0];
    REP(i, 1000002) {
        A[i + 1] += A[i];
        max = std::max(A[i + 1], max);
    }

    cout << max << endl;

    return 0;
}