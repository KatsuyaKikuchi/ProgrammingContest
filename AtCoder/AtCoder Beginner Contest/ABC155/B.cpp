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
    bool t = true;
    REP(i, N) {
        if (A[i] % 2 == 1)
            continue;
        if (A[i] % 3 == 0)
            continue;
        if (A[i] % 5 == 0)
            continue;
        t = false;
    }

    if (t)
        cout << "APPROVED" << endl;
    else
        cout << "DENIED" << endl;
    return 0;
}