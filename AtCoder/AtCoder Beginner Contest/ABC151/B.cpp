#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200];

int main() {
    ll N, K, M;
    cin >> N >> K >> M;
    ll S = 0;
    REP(i, N - 1) {
        cin >> A[i];
        S += A[i];
    }

    REP(i, K + 1) {
        if ((S + i) / N >= M) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}