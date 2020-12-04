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
ll D[100005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N - 1) {
        D[i] = A[i + 1] - A[i];
    }

    REP(i, N - 1) {
        if (D[i] < 0)
            cout << "down " << abs(D[i]) << endl;
        else if (D[i] > 0)
            cout << "up " << D[i] << endl;
        else
            cout << "stay" << endl;
    }

    return 0;
}