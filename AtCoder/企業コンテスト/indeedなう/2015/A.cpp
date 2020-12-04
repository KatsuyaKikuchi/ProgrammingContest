#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[105];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N);

    ll max = -INF, min = INF;
    REP(i, N) {
        min = std::min(A[i] + A[N - 1 - i], min);
        max = std::max(A[i] + A[N - 1 - i], max);
    }
    cout << max - min << endl;
    return 0;
}