#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K, S, T;
    cin >> N >> K >> S >> T;
    REP(i, N) {
        cin >> A[i];
    }
    return 0;
}